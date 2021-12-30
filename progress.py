#!/usr/bin/env python3

import argparse
import json
import csv
import git
import os
import re
import math

parser = argparse.ArgumentParser(description="Computes current decompilation progress")
parser.add_argument("-s", "--silent", dest='silent', action='store_true', help="Run silently")
parser.add_argument("-u", "--update", dest='update', action='store_true', help="Update the readme")
parser.add_argument("-d", "--dumpcsv", dest='dumpcsv', action='store_true', help="Append progress data to csv file")
parser.add_argument("-f", "--csvfile", dest='csvfile', type=str, default="")
parser.add_argument("-v", "--version", dest='gameversion', type=str, default="us")
args = parser.parse_args()

NON_MATCHING_PATTERN = re.compile(
    r"#if.*?NON_MATCHING.*?INCLUDE_ASM\(\s*\"(.*?)\", (\w+).*?\).*",
    re.DOTALL | re.MULTILINE
)

STRIP_C_COMMENTS_RE = re.compile(
    r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
    re.DOTALL | re.MULTILINE
)

PROGRAM = "turok3"

def strip_c_comments(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith("/"):
            return " "
        else:
            return s
    return re.sub(STRIP_C_COMMENTS_RE, replacer, text)

def GetNonMatchingFunctions(files):
    functions = []

    for file in files:
        with open(file, "r") as f:
            text = strip_c_comments(f.read())
            for match in NON_MATCHING_PATTERN.finditer(text):
                functions.append(match.group(1) + "/" + match.group(2) + ".s")

    return functions

def ReadAllLines(fileName):
    lineList = list()
    with open(fileName) as f:
        lineList = f.readlines()

    return lineList

def GetFiles(path, ext):
    files = []

    for r, d, f in os.walk(path):
        for file in f:
            if file.endswith(ext):
                files.append(os.path.join(r, file))

    return files

def GetNonMatchingSize(path):
    size = 0
    asmFiles = GetFiles(path, ".s")

    for asmFilePath in asmFiles:
        if asmFilePath not in nonMatchingFunctions:
            asmLines = ReadAllLines(asmFilePath)

            for asmLine in asmLines:
                if (asmLine.startswith("/*")):
                    size += 4

    return size

def UpdateReadme(tofind, pct):
    with open('README.md', 'r') as file:
        filedata = file.read()

    index = filedata.find(tofind)
    if (not index == -1):
        index += len(tofind)
        qndex = filedata.find("-", index)
        if (not qndex == -1):
            filedata = filedata.replace(filedata[index:qndex], '%.2f' % pct, 1)

    with open('README.md', 'w') as file:
        file.write(filedata)

versionDir = "versions/" + args.gameversion + "/"
buildDir = versionDir + "build/"
mapFile = ReadAllLines(buildDir + PROGRAM + "." + args.gameversion + ".map")
src = 0
asm = 0

for line in mapFile:
    lineSplit =  list(filter(None, line.split(" ")))

    if (len(lineSplit) == 4 and lineSplit[0].startswith(".")):
        section = lineSplit[0]
        size = int(lineSplit[2], 16)
        objFile = lineSplit[3]

        if (section == ".text"):
            if (objFile.startswith(buildDir + "src")):
                src += size
            elif (objFile.startswith(buildDir + "asm")):
                asm += size

total = src + asm

nonMatchingFunctions = []
nonMatchingSize = GetNonMatchingSize(versionDir + "asm/nonmatchings")
srcSize = src - nonMatchingSize
asmSize = asm + nonMatchingSize

nonMatchingFunctions = GetNonMatchingFunctions(GetFiles("src/" + args.gameversion, ".c"))
nonMatchingFunctionsCommon = GetNonMatchingFunctions(GetFiles("src/common", ".c"))

# Add nonMatchingFunctions from common to list
for nonMatchingFunc in nonMatchingFunctionsCommon:
    nonMatchingFunctions.append(nonMatchingFunc)

# Fix paths
for index in range(len(nonMatchingFunctions)):
    nonMatchingFunctions[index] = versionDir + nonMatchingFunctions[index]


nonMatchingSize = GetNonMatchingSize(versionDir + "asm/nonmatchings")
nonMatchingSrcSize = src - nonMatchingSize
nonMatchingAsmSize = asm + nonMatchingSize

srcPct = 100 * srcSize / total
asmPct = 100 * asmSize / total
nonMatchingSrcPct = 100 * nonMatchingSrcSize / total
nonMatchingAsmPct = 100 * nonMatchingAsmSize / total

hexformat = '%06x'

levelNames = [
    [
        "CINEMA - Introl",
        "CINEMA - 1 - Dream Cinema",
        "CINEMA - 2 - Porch Cinema",
        "CINEMA - 3 - House Cinema",
        "CINEMA - 4 - Car Cinema",
        "CINEMA - 5 - Council cinema",
        "CINEMA - Player select Danny",
        "CINEMA - Player select Joseph"
    ],
    [
        "1.1.1#The Breach",
        "1.1.2#Unexpected Help",
        "1.2.1#City Streets",
        "1.2.2#The Back Alleys",
        "1.2.3#Rooftop Journey",
        "1.2.M#The Museum",
        "1.2.4#Block Party",
        "1.3.1#The Sewers",
        "1.3.2#To The Subway",
        "CINEMA - 1.3 Subway Start - Danny",
        "1.3.4#On The Tracks"
        "CINEMA - 1.3 Subway Crash Cinema",
        "CINEMA - 1.3 Subway Doesnt Crash",
        "1.3.5#Train Ride",
        "1.4.1#Power Outage",
        "(Lev 1 Boss Arena)#Hole In The Sky"
    ],
    [
        "2.1.1#The Military Base",
        "2.1.2#Corridors of Pain",
        "2.1.3#Main Access",
        "2.1.4#Topside",
        "2.1.5#Main Access",
        "CINEMA - 2.1.5 Dead Scientist Cinema",
        "2.1.6#Silos 2, 3 and 4",
        "2.1.7#Silo 1",
        "2.2.1#Dark Hangar",
        "2.2.1.j#Dark Hangar",
        "2.2.2#The Warehouses",
        "CINEMA - 2.23.Lair of the Crabtopus",
        "2.10#Dark Hangar",
        "2.11#Hit The Lights",
        "2.12d#Into The Barracks.",
        "2.19#The Barracks",
        "2.20#Rec Room",
        "2.21#Undersea Observatory",
        "2.23#The Sub Pen"
    ],
    [
        "3.1.1#Lost Land Junkyard",
        "3.1.2#Metal Mine",
        "3.1.3#Plane Wreck",
        "3.1.4#The Drain",
        "3.1.5#Generator Room",
        "3.A.6#The Lab",
        "3.B.6#The Dam ",
        "3.1.7#Into The Jungle",
        "3.1.8#The Foyer",
        "3.1.9#The Opisthor's Chamber"
    ],
    [
        "4.0.0#Heart Of Fire",
        "4.1.1#Echos of the Past",
        "4.1.2#Narrow Passage",
        "4.1.3#Ancient Altar",
        "4.2#Seal The Breach",
        "4.2.1#Canyon Blockade",
        "4.2.2#Bunker Assault",
        "4.2.3#Command Center",
        "4.2.4#Final Gate",
        "4.3.1#Temple of the Damned",
        "4.3.2#Gate to Oblivion",
        "4.4.1#Fiery Encounter",
        "4.4.2#Aerial Journey",
        "4.4.3#The Nursery",
        "4.4.4#Burning Passage",
        "4.4.5#Heart of Fire"
    ],
    [
        "CINEMA - level 5 intro",
        "5.1.0#Welcoming Committee",
        "5-1-1#The Outskirts",
        "5-1-2#Chaos Entrance",
        "5-2-1#Drilling Sector",
        "5-2-2#Ore Transport",
        "5-3-1#The Gauntlet",
        "5-3-2#Refinery One",
        "5-4-1#Central Nexus",
        "5-4-2#Staging Area",
        "5-4-3#Crystal Processing",
        "5-4-4#Refinery Two",
        "5-5-1#Undershaft Down",
        "5-5-2#Undershaft Halls",
        "5-5-3#In The Grasp Of Oblivion",
        "CINEMA - joshuablivion end",
        "CINEMA - Oblivion Arena Cinema",
        "CINEMA - Adon Rebels ",
        "CINEMA - Josh is Evil cinema"
    ]
]

chapters = len(levelNames)
totalLevels = 0
for levels in levelNames:
    totalLevels += len(levels)


if (args.dumpcsv):
    git_object = git.Repo().head.object
    data = [
        str(git_object.committed_date),
        git_object.hexsha,
        str(srcSize), str(asmSize),
        str(nonMatchingSrcSize), str(nonMatchingAsmSize),
        str(len(nonMatchingFunctions)),
        str(total)
    ]

    if (not args.silent):
        print(",".join(data))

    dir = args.csvfile
    if (dir == ""):
        dir = "progress.csv"

    with open(dir, 'a') as file:
        file.write("\n" + ",".join(data))

if (not args.silent):
    levelIndex = math.floor((nonMatchingSrcSize / total) * totalLevels)
    chapter = math.floor((nonMatchingSrcSize / total) * chapters)
    levelCounter = levelIndex

    # Super laziness
    for levels in levelNames:
        if (len(levels) > levelCounter): break
        else: levelCounter -= len(levels)

    levelName = levelNames[chapter][levelIndex]
    psg = math.floor((srcSize / total) * 5)

    print(args.gameversion)
    print("0x" + (hexformat % total).upper() + " total bytes of decompilable code")
    print("\033[0;32m0x" + (hexformat % srcSize).upper() + " / 0x" + (hexformat % total).upper() + " matching   (" + str(srcPct) + "%)\033[0;0m")
    print("\033[0;33m0x" + (hexformat % nonMatchingSrcSize).upper() + " / 0x" + (hexformat % total).upper() + " decompiled (" + str(nonMatchingSrcPct) + "%)\033[0;0m")
    print("------------------------------------")
    print("You are on " + levelName)
    print("You have collected " + str(psg) + " / " + str(5) + " PSG parts!")

if (args.update):
    UpdateReadme("/matched-", srcPct)
    UpdateReadme("/decompiled-", nonMatchingSrcPct)
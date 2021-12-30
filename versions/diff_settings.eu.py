#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = f'versions/eu/build/turok3.eu.map'
    config['myimg'] = f'versions/eu/build/turok3.eu.z64'
    config['baseimg'] = f'versions/baserom.eu.z64'
    config['source_directories'] = ['src/eu', 'src/common', 'include', 'versions/eu/asm']

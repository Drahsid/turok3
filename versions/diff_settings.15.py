#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = f'versions/15/build/turok3.15.map'
    config['myimg'] = f'versions/15/build/turok3.15.z64'
    config['baseimg'] = f'versions/baserom.15.z64'
    config['source_directories'] = ['src/15', 'src/common', 'include', 'versions/15/asm']

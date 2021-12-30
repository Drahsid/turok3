#!/usr/bin/env python3

def apply(config, args):
    config['mapfile'] = f'versions/09/build/turok3.09.map'
    config['myimg'] = f'versions/09/build/turok3.09.z64'
    config['baseimg'] = f'versions/baserom.09.z64'
    config['source_directories'] = ['src/09', 'src/common', 'include', 'versions/09/asm']

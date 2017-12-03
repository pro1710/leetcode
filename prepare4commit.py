import os
import re

source_file = 'ready4commit.txt'

if source_file not in os.listdir():
    raise Exception('No such file:', source_file)


content = {}
with open(source_file, 'r') as f:
    out = None
    for line in f:
        if re.match(r'\/\/\s\d+[a-z_]+\.cpp', line):
            if out:
                out.close()
                
            output_file = line.split()[1]
            print('New file:', output_file)
            out = open(output_file, 'w')
        
        out.write(line)
    if out:
        out.close()
                



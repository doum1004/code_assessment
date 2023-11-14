# write python script to generate empty file with extensions given from arguments
# usage: python dummy.py filename extension1 extension2 extension3 ...
# example: python dummy.py test .py .txt .cpp .c
#
import sys
import os

if len(sys.argv) < 3:
    print("usage: python dummy.py filename extension1 extension2 extension3 ...")
    sys.exit(1)

filename = sys.argv[1]
extensions = sys.argv[2:]

for extension in extensions:
    # path with current dir
    path = os.path.join(os.getcwd(), filename + '.' + extension)
    print(path)
    if os.path.exists(path):
        print("file %s already exists" % path)
    else:
        open(path, 'a').close()
        
print("done")

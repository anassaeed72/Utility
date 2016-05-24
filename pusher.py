import sys
import os
command   = "git add " + sys.argv[1]
print command
os.system(command)
# print command
command = "git commit -m \"" + sys.argv[1] +"\""
print command
os.system(command)
command = "git push origin master"
os.system(command)
print"Done"
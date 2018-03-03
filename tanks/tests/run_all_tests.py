#!/bin/python3
import sys
import os
import re
import subprocess

def isExe(fpath):
    return os.path.isfile(fpath) and os.access(fpath, os.X_OK)

def findBuildDir():
    for dir in os.listdir(".."):
        if dir.find("build") != -1:
            return "../" + dir
    return None

def changeToBuildDir(buildDir):
    os.chdir(buildDir)

def changeToTestsFolder():
    os.chdir("tests")
    print("Now in:", os.getcwd())

def executeOneTestSuite(exe):
    subprocess.run([exe])

def getTestDirs():
    return [ dir for dir in os.listdir(".") if dir.startswith("test") ]

def getExecutables(dir):
    return [ exec for exec in os.listdir(dir) if isExe(dir + "/" + exec) ]

def runTests():
    for dir in getTestDirs():
        for file in getExecutables(dir):
            executeOneTestSuite(dir+"/"+file)

def runAllTests():
    ## find the build dir
    try:
        buildDir = findBuildDir()
        changeToBuildDir(buildDir)
        changeToTestsFolder()
        runTests()
    except Exception as e:
        print(str(e))
        exit(1)


def main():
    print("Started runner from: " + os.getcwd() + ".")
    runAllTests()

if __name__ == "__main__":
    main()

#!/usr/bin/python
import sys
import os
import string

def processHashChar(ss):
  ds = ss.split('#')[0]
  return ds.replace(' ', '')
  
def main():
  f = open('list-of-test-cases.txt', 'r')
  testCaseList = f.readlines()
  print '============================'
  for testCaseItem in testCaseList:
    if (testCaseItem[0] == '\n'):
      continue
    testCaseItem = testCaseItem.rstrip(' \n\t')
    if ('#' in testCaseItem):
      testCaseDir = processHashChar(testCaseItem);
    else:
      testCaseDir = testCaseItem
    os.chdir('%s'%(testCaseDir))
    os.system('../../sv.exe %s.sv > %s-Run.txt'%(testCaseDir,testCaseDir))
    os.system ('diff %s-Run.txt %s-Gold.txt > %s-Diff.txt'%(testCaseDir,testCaseDir,testCaseDir)) 
    if (os.stat('%s-Diff.txt'%(testCaseDir)).st_size == 0):
      print '%s ::: PASSED'%(testCaseDir)
    else:
      print '%s ::: FAILED'%(testCaseDir)
    print '============================'
    os.chdir('..')

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-12-02 12:51:15
LastEditors: lxp
LastEditTime: 2021-12-02 13:05:06
'''
from os import system as git_command

git_command('git status')
git_commit_text = input("Enter Push Record Content: ")
print("git_commit_text(no space): ", git_commit_text)
git_command('git add .')
git_commit = "git commit -m " + git_commit_text
git_command(git_commit)
git_command('git status')
# git_command('git push origin main')
print("Please Hand Input: \n git push origin main")
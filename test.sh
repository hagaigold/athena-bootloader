#!/bin/bash

last_tag=$(git describe --long --dirty --tags)
tokens=(${last_tag//-/ })
number_of_commits_from_last_tag=${tokens[1]} 

#echo ${last_tag}
#echo ${number_of_commits_from_last_tag}

if [ ${number_of_commits_from_last_tag} -gt 0 ]
then
    echo 'do work'
else
    echo 'nothing to do...'
fi


if ! (git log -1 --pretty=format:'%an' | grep -iq buildbot)
then
    echo 'do work'
    exit 0
else
    echo 'nothing to do...'
    exit 1
fi

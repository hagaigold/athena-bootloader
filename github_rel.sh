#!/bin/bash

#echo $GITHUB_TOKEN

last_tag=$(git describe --long --dirty --tags)
#tokens=(${last_tag//-/ })
#BUILD_TAG=${tokens[0]} 

echo ${last_tag}
echo ${BUILD_TAG}

git tag -a ${BUILD_TAG} -m "Updating firmware images."
git push origin ${BUILD_TAG}

echo "Creating a new release in github"

# github-release delete \
#     --user hagaigold \
#     --repo athena-bootloader \
#     --tag ${BUILD_TAG}

github-release release \
    --user hagaigold \
    --repo athena-bootloader \
    --tag ${BUILD_TAG} \
    --name ${BUILD_TAG} \
    --pre-release


echo "upload files..."

github-release upload \
    --user hagaigold \
    --repo athena-bootloader \
    --tag ${BUILD_TAG} \
    --name "athena_bootloaders-${BUILD_TAG}.zip" \
    --file buildresults/release/athena_bootloaders-${BUILD_TAG}.zip

github-release upload \
    --user hagaigold \
    --repo athena-bootloader \
    --tag ${BUILD_TAG} \
    --name "athena_bootloaders-bm-${BUILD_TAG}.zip" \
    --file buildresults/release/athena_bootloaders-bm-${BUILD_TAG}.zip
    
#--file stam.zip

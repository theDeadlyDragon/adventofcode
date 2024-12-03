#!/usr/bin/env bash


RunPremake() {
    FILE=premake5
    cd vendor/
    if test -f "$FILE"; then
        ./premake5 cmake
    else
        DownloadPremake
    fi
}

DownloadPremake(){
    fileVersion=premake-5.0.0-beta3-src.zip  
    git clone https://github.com/premake/premake-core.git
    ./premake-core/Bootstrap.sh

    cp premake-core/bin/release/premake5 premake5
    chmod 755 premake5 

    rm -rf premake-core 

    #add cmake toolchain to premake
    git clone https://github.com/Jarod42/premake-cmake.git
    
    cp -R premake-cmake/*.lua ../vendor
    rm -rf premake-cmake 

    cd ..
}

RunPremake



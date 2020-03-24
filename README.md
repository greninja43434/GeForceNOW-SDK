# NVIDIA GeForce NOW SDK Release 1.1

## At a Glance

The GeForce NOW SDK (GFNSDK) is a means for game developers and publishers to directly integrate with GeForce NOW, NVIDIA's Cloud Gaming Service. This service allows gamers to experience GeForce gaming anywhere, as well as allowing publishers and game developers to take advantage of high-performance rendering through NVIDIA's top-notch DirectX and Vulkan drivers on both Windows and Linux platforms. 

The GFN SDK is ever-evolving to provide easy integration of GeForce NOW features into publisher applications and games, as well as more efficient way to integrate games into the GeForce NOW ecosystem. 

Please refer to the [GFN SDK Primer](./doc/GFN-SDK-PRIMER.pdf) for a more detailed overview of the features.

### What's New in This Release
* X86 support for X86-based titles.
* New StartStream callback that provides status notifications while the streaming is starting up.
* Implemented support for timeout in gfnStartStreamAsync.
* Documentation correction along with some minor cleanup.
* Crash and bug fixes in the APIs.
* Crash and bug fixes in the Launcher sample.

## Developer Content Portal

* If your organization or game isn't yet registered with NVIDIA, visit the [Developer Content Portal](https://portal-developer.nvidia.com/) to create accounts and complete game registration.

## Development Guide

### Software Stack

![Software Stack](./doc/img/software_stack.png)

Each feature has different integration points. Some features define REST Web APIs, while others integrate into the game or publisher application with native C interfaces. Refer to documentation for each feature in the doc folder.

Some features require a compatible version of GeForce NOW to be installed on the client system. The integrated GFNSDK components are designed to take care of downloading and installing GeForce NOW client when needed.

### GeForce NOW SDK Package

The distribution is laid out as below:
```
.
+-- CMakeLists.txt
+-- generate.bat
+-- generate_x86.bat
+-- LICENSE
+-- README.md
+-- doc
|       GFN-SDK-RUNTIME
+--     index.html
|       GFN-SDK-PRIMER.pdf
|       SDK-GFN-NGN-ENDPOINT.pdf
|       SDK-GFN-SUPPORTED-TITLES.pdf
+-- include
|       GfnRuntimeSdk_CAPI.h
+-- lib
+-- samples
|       SampleCApp
|       SampleLauncher
|       README.md
```

### Additional Documentation Online

In addition to the documents included in /doc in this repository, there are online documentation resources for some of the features.

* For game and launcher related APIs, please refer to the [NVIDIA Developer Services API Help](https://portal-developer.nvidia.com/help/).
* For account-related APIs, please refer to the Swagger documentation in the [NVIDIA Identity Service API Help](https://devportal.nvgs.nvidia.com/docs/api-docs-proxy/docs/api/jarvis/help/docs).
   * OAuth APIs are documented under the "OAuth 2.0 Provider" item in the "API group" pulldown menu.
   * Token APIs are documented under the "Authentication" item in the "API group" pulldown menu. 
Please note that the documentation for Account and IDM-related APIs are not public and require your NVIDIA account to be granted access. To request access, visit the [Developer Portal](https://devportal.nvgs.nvidia.com) or contact NVIDIA Developer Relations.




// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2020-2021 NVIDIA Corporation. All rights reserved.

//
// ===============================================================================================
//
// C API declarations for GFN Runtime SDK
//
// ===============================================================================================
/**
 * @file GfnRuntimeSdk_CAPI.h
 *
 * API definitions
 */
///
/// @mainpage Native Runtime Application Programming Interface Reference
///
/// @section introduction Introduction
/// The NVIDIA GFN Runtime SDK provides an Application Programming Interface (API)
/// to allow game and application developers to interact with parts of the NVIDIA
/// GeForce NOW ecosystem. Overall integration is provided by various interfaces,
/// from the native C interfaces described in this documentation, to RESTful
/// endpoint calls, depending on the feature of the SDK. 
/// 
/// This documenation focuses solely on the native C interfaces, and provides the
/// specifications of each of the native APIs of GFN Runtime SDK, as well as the
/// requires to use the APIs. For example usage, refer to the Quick Start 
/// documentation and the sample applications provided in the ./samples folder.
///
/// @section overview Overview
///
/// The GFN Runtime SDK provides a dynamic library with API exports as defined in
/// this document, which is distributed with and loaded by the game/application that
/// utilizes the APIs. The loading of this library should be done in a way that
/// validates the authenticity of the binary. For example, on Windows, checking for
/// a valid digital signature, and that signature is from NVIDIA Corporation.
///
/// The behavior of the APIs depends on the environment the application is running in;
/// either on a client/user system or in the GeForce NOW (GFN) cloud environment. Each
/// API defines which of the environments it is designed to run in. Some of the APIs
/// can execute in only one of the environments; either the local client or GFN cloud
/// environment. These APIs will return a well-defined error code "gfnCallWrongEnvironment"
/// to denote when call was not applicable to the execution environment.
///
/// For additional high-level overview, please refer to the SDK primer available as
/// part of the documentation section of the SDK's repository. For references on 
/// correct API calls for the most common of integration scenarios, please prefer to
/// the SDK Quick Start Guide.
///
/// @section keyconcepts Key Concepts
///
/// GFN Runtime API methods are used to make requests from or to notify the GFN
/// backend.
///
/// When your application is operating outside of the GFN environment, these
/// methods are simple stubs that incur almost no cost, so it's safe to add
/// these to your main build.
///
/// The calling convention differs by which API you've selected to use. In most
/// cases, the methods return a GfnRuntimeError result, which can be used by the
/// application to check for errors. In addition, some methods are asynchronous
/// by nature, but provide synchronous variants when possible.
///
/// @section apiReference API Reference
/// @subsection general_section General / Common methods
/// @ref general
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnInitializeRuntimeSdk
///
/// @copydoc gfnInitializeRuntimeSdk
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnShutdownRuntimeSdk
///
/// @copydoc gfnShutdownRuntimeSdk
///
/// @subsection launcher_game_section Launcher or Game Specific Methods
/// @ref launcher
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnIsRunningInCloud
///
/// @copydoc gfnIsRunningInCloud
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnIsRunningInCloudSecure
///
/// @copydoc gfnIsRunningInCloudSecure
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnFree
///
/// @copydoc gfnFree
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnIsTitleAvailable
///
/// @copydoc gfnIsTitleAvailable
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetTitlesAvailable
///
/// @copydoc gfnGetTitlesAvailable
///
/// Language | API
/// -------- | -------------------------------------
/// C sync   | @ref gfnSetupTitle
///
/// @copydoc gfnSetupTitle
///
/// Language | API
/// -------- | -------------------------------------
/// C sync   | @ref gfnTitleExited
///
/// @copydoc gfnTitleExited
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetClientIp
///
/// @copydoc gfnGetClientIp
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetClientLanguageCode
///
/// @copydoc gfnGetClientLanguageCode
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetClientCountryCode
///
/// @copydoc gfnGetClientCountryCode
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetClientInfo
///
/// @copydoc gfnGetClientInfo
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetSessionInfo
///
/// @copydoc gfnGetSessionInfo
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnStartStream
///
/// @copydoc gfnStartStream
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnStartStreamAsync
///
/// @copydoc gfnStartStreamAsync
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnStopStream
///
/// @copydoc gfnStopStream
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnStopStreamAsync
///
/// @copydoc gfnStopStreamAsync
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetPartnerData
///
/// @copydoc gfnGetPartnerData
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnGetPartnerSecureData
///
/// @copydoc gfnGetPartnerSecureData
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnAppReady
///
/// @copydoc gfnAppReady
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnSetActionZone
///
/// @copydoc gfnSetActionZone
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnSendMessage
///
/// @copydoc gfnSendMessage
///
/// @subsection callback_section Callback-related Methods
/// @ref callbacks
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterExitCallback
///
/// @copydoc gfnRegisterExitCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterPauseCallback
///
/// @copydoc gfnRegisterPauseCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterInstallCallback
///
/// @copydoc gfnRegisterInstallCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterStreamStatusCallback
///
/// @copydoc gfnRegisterStreamStatusCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterSessionInitCallback
///
/// @copydoc gfnRegisterSessionInitCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterClientInfoCallback
///
/// @copydoc gfnRegisterClientInfoCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterNetworkStatusCallback
///
/// @copydoc gfnRegisterNetworkStatusCallback
///
/// Language | API
/// -------- | -------------------------------------
/// C        | @ref gfnRegisterMessageCallback
///
/// @copydoc gfnRegisterMessageCallback

#ifndef GFN_SDK_RUNTIME_CAPI_H
#define GFN_SDK_RUNTIME_CAPI_H


#include "GfnSdk.h"

// Defining GfnRuntimeError for backwards compatibility
#define GfnRuntimeError GfnError

#ifdef __cplusplus
    extern "C"
    {
#endif
        // ============================================================================================
        // Constants/Enums
        // ============================================================================================

        /** @brief Returned by callbacks the application registers with the Geforce NOW Runtime SDK, or passes
         *  in to asynchronous SDK calls.
         */
        typedef enum GfnApplicationCallbackResult
        {
            crCallbackSuccess =  0, ///< Return to indicate that a callback has performed the requested operation
            crCallbackFailure = -1  ///< Return to indicate that a callback did not perform the requested operation
        } GfnApplicationCallbackResult;

        /** @brief Returned from @ref gfnIsRunningInCloudSecure to denote security assurance that the calling application is running, untampered,
        *   in the GFN cloud environment.
         */
        typedef enum GfnIsRunningInCloudAssurance
        {
            gfnNotCloud = 0,                  ///< Not considered to be running in GFN cloud, as it looks like a client/local system.
            gfnIsCloudLowAssurance = 1,       ///< Considered to be running in GFN Cloud, using software heuristics that are not guaranteed against circumvention.
            gfnIsCloudMidAssurance = 2,       ///< Considered to be running in GFN Cloud, using software and network heuristics that are difficult to circumvent.
            gfnIsCloudHighAssurance = 3       ///< Considered to be running in GFN Cloud, using software and hardware heuristics that are near impossible to circumvent.
        } GfnIsRunningInCloudAssurance;

        /// @brief Output response when streaming has started
        typedef struct StartStreamResponse
        {
            bool downloaded; ///< True if Geforce NOW client components were downloaded from the release site.
        } StartStreamResponse;

        /// @brief Callback function signation for notifications on status of starting a streaming session.
        typedef void(GFN_CALLBACK *StartStreamCallbackSig)(GfnRuntimeError, StartStreamResponse*, void* context);

        /// @brief Callback function signation for notifications on status of stop a streaming session.
        typedef void(GFN_CALLBACK* StopStreamCallbackSig)(GfnRuntimeError, void* context);

        /// @brief Input data for gfnStartStream
        typedef struct StartStreamInput
        {
            unsigned int uiTitleId;             ///< GFN-sourced game-specific unique identifier.
            const char* pchPartnerData;         ///< Optional non-secure partner data that is passed to the streaming cloud instance and can be retrieved in that instance of application.
            const char* pchPartnerSecureData;   ///< Optional secure partner data that is guaranteed to be protected through the GFN pipeline.
        } StartStreamInput;

        /// @brief Input to the function registered via gfnRegisterInstallCallback (if any).
        typedef struct TitleInstallationInformation
        {
            const char* pchPlatformAppId; ///< Platform application ID passed into the API.
            const char* pchBuildPath;     ///< The path at which game build files can be found.
            const char* pchMetadataPath;  ///< Optionally contains the path at which game metadata can be found, else NULL.
        } TitleInstallationInformation;

        /// @brief Possible states of the client streamer
        typedef enum GfnStreamStatus
        {
            GfnStreamStatusInit,           ///< Initial default state
            GfnStreamStatusNetworkTest,    ///< Client is running a network test to determine the best zone
            GfnStreamStatusLoading,        ///< Client is loading the game
            GfnStreamStatusStreaming,      ///< Client is actively streaming
            GfnStreamStatusDone,           ///< Client has successfully finished streaming
            GfnStreamStatusError,          ///< Client has stopped streaming and has entered an error state
            GfnStreamStatusGotInputFocus,  ///< Client has gained input focus to the streamer window
            GfnStreamStatusLostInputFocus  ///< Client has lost input focus to the streamer window
        } GfnStreamStatus;

        /// @brief Converts a GfnStreamStatus enum to a human-readable string
        inline const char* GfnStreamStatusToString(GfnStreamStatus status)
        {
            switch (status)
            {
            case GfnStreamStatusInit:           return "Init";
            case GfnStreamStatusNetworkTest:    return "NetworkTest";
            case GfnStreamStatusLoading:        return "Loading";
            case GfnStreamStatusStreaming:      return "Streaming";
            case GfnStreamStatusDone:           return "Done";
            case GfnStreamStatusError:          return "Error";
            case GfnStreamStatusGotInputFocus:  return "GotInputFocus";
            case GfnStreamStatusLostInputFocus: return "LostInputFocus";
            }
            return "Unknown GfnStreamStatus";
        }


        /// @brief Specifies the action in GfnSetActionZone API
        /// Deprecated with SetActionZone removal
        typedef enum GfnActionType
        {
            gfnActionNone = 0,    ///< No event
            gfnEditBox = 1,       ///< Action to specify an editable text box rect on screen
            gfnActionMAX          ///< Sentinel value, do not use
        } GfnActionType;


    #define IP_V4_SIZE              (17) // INET_ADDRSTRLEN + NULL
    #define IP_V6_SIZE              (49) // INET6_ADDRSTRLEN + NULL
    #define CC_SIZE                 (3)  // ISO 3166-1 Alpha-2
    #define LOCALE_SIZE             (6)  // ISO 639-1 Alpha-2
    #define SESSION_ID_SIZE         (38)

        /// @brief Types of operating systems that can be reported by the SDK
        typedef enum GfnOsType
        {
            gfnUnknownOs = 0,
            gfnWindows = 1,
            gfnMacOs = 2,
            gfnShield = 3,
            gfnAndroid = 4,
            gfnIOs = 5,
            gfnIPadOs = 6,
            gfnChromeOs = 7,
            gfnLinux = 8,
            gfnTizen = 9,
            gfnWebOs = 10,
            gfnTvOs = 11,
            gfnOsTypeMax = 11
        } GfnOsType;

        /// @brief Client info blob
        typedef struct
        {
            unsigned int version;               ///< Deprecated, value will be ignored
            GfnOsType osType;                   ///< Operating System type
            char ipV4[IP_V4_SIZE];              ///< IPV4 address, example - "192.168.0.1"
            char country[CC_SIZE];              ///< ISO 3166-1 alpha-2 standard country code, example - "us"
            char locale[LOCALE_SIZE];           ///< ISO 639-1 Alpha-2 standard locale, example - "en-us"
            unsigned int RTDAverageLatencyMs;   ///< Round Trip Delay - Average Latency in milliseconds
            GfnResolutionInfo clientResolution; ///< Client device's physical resolution, if reported. If client does not report, expect values of zero.
        } GfnClientInfo;

        /// @brief Type of data which changed. This enum will be expanded over time
        typedef enum GfnClientInfoChangeType
        {
            gfnOs = 0,                          ///< Change in OS of GFN Client
            gfnIP = 1,                          ///< Change in IP of GFN Client (due to device switch/reconnect)
            gfnClientResolution = 2,            ///< Change in resolution of GFN Client
            gfnSafeZone = 3,                    ///< Change in safe zone rectangle (due to device switch or rotation)
            gfnClientDataChangeTypeMax = 3      ///< Sentinel value for GfnClientInfoChangeType
        } GfnClientDataChangeType;

        /// @brief An update notification for a piece of client info data
        typedef struct GfnClientInfoUpdateData
        {
            unsigned int version;               ///< Deprecated, value will be ignored
            GfnClientDataChangeType updateType; ///< Type of GFN Client data that changed
            union
            {
                GfnOsType osType;               ///< Operating System type
                char ipV4[IP_V4_SIZE];          ///< IPV4 address, example - "192.168.0.1"
                GfnResolutionInfo clientResolution; ///< Client device's physical resolution, if reported. If client does not report, expect values of zero.
                GfnRect safeZone;                   ///< Client safe zone rectangle (title-safe area), in normalized coordinates. If the entire screen is title-safe because of device type, then expect values of zero.
            } data;
        } GfnClientInfoUpdateData;

        /// @brief The type of network status data which changed. This enum will likely be expanded over time.
        typedef enum GfnNetworkStatusChangeType
        {
            gfnRTDAverageLatency          = 0, ///< Change in RTDAverageLatency
            gfnNetworkStatusChangeTypeMax = 0  ///< Sentinel value for GfnNetworkStatusChangeType
        } GfnNetworkStatusChangeType;

        /// @brief An update notification for a piece of network status data. This structure will likely be expanded over time.
        typedef struct GfnNetworkStatusUpdateData
        {
            unsigned int version;                   ///< Deprecated, value will be ignored
            GfnNetworkStatusChangeType updateType;  ///< Network Status Update type
            union
            {
                unsigned int RTDAverageLatencyMs;   ///< Round Trip Delay - Average Latency in milliseconds
            } data;
        } GfnNetworkStatusUpdateData;


        /// @brief Session info blob
        typedef struct
        {
            unsigned int sessionMaxDurationSec;      ///< Maximum total time allowed for the session in seconds
            unsigned int sessionTimeRemainingSec;    ///< Nominal time remaining in the session in seconds
            char sessionId[SESSION_ID_SIZE];         ///< NVIDIA-defined unique indentifier for the session
            bool sessionRTXEnabled;                  ///< Defines if RTX support is enabled for the session
        } GfnSessionInfo;

        // ============================================================================================
        // Callback signatures
        // ============================================================================================

        // Callbacks that client code should implement and register via the appropriate callback
        // registration function (listed as part of the C API below).
        /// @brief Callback function for notification when a game should exit. Register via gfnRegisterExitCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK *ExitCallbackSig)(void* pUserContext);
        /// @brief Callback function for notification when a game should pause. Register via gfnRegisterPauseCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK *PauseCallbackSig)(void* pUserContext);
        /// @brief Callback function for notification when a game is being installed to allow for installation actions. Register via gfnRegisterInstallCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK *InstallCallbackSig)(const TitleInstallationInformation* pInfo, void* pUserContext);
        /// @brief Callback function for notifications on status of starting a streaming session. Register via gfnRegisterStreamStatusCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK *StreamStatusCallbackSig)(GfnStreamStatus status, void* pUserContext);
        /// @brief Callback function for notifications when a game should save its state. Register via gfnRegisterSaveCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK* SaveCallbackSig)(void* pUserContext);
        /// @brief Callback function for notifications when a game should continue late-stage initialization. Register via gfnRegisterSessionInitCallback API.
        /// Function should consume or copy the passed-in partnerInfoMutable string
        typedef GfnApplicationCallbackResult(GFN_CALLBACK* SessionInitCallbackSig)(const char* partnerInfoMutable, void* pUserContext);
        /// @brief Callback function for notifications on client info changes. Register via gfnRegisterClientInfoCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK* ClientInfoCallbackSig)(GfnClientInfoUpdateData* pUpdate, const void* pUserContext);
        /// @brief Callback function for notifications on network status changes. Register via gfnRegisterNetworkStatusCallback API.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK* NetworkStatusCallbackSig)(GfnNetworkStatusUpdateData* pUpdate, const void* pUserContext);
        /// @brief Callback function for notifications when an application recieves a custom message.
        typedef GfnApplicationCallbackResult(GFN_CALLBACK* MessageCallbackSig)(const GfnString* pStrData, void* pUserContext);

        // ============================================================================================
        // C API
        // ============================================================================================

        // ============================================================================================
        // SDK Initialization / Shutdown

        /// @defgroup general General / Common Methods
        /// The functions contained in this section control the lifecycle of the SDK.
        /// @{

        /// @par Description
        /// Should be called at application startup and prior to any other GFN Runtime API methods.
        /// The SDK features which become available as a result of initializing the Geforce NOW
        /// SDK are dependent on the type of environment in which the SDK operates (client or cloud).
        ///
        /// @par Environment
        /// Cloud and Client
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call as soon as possible during application startup.
        ///
        /// @param displayLanguage            - Language to use for any UI, such as GFN download and install progress dialogs.
        ///                                     Defaults to system language if not defined.
        /// @retval gfnSuccess                - If the SDK was initialized and all SDK features are available.
        /// @retval gfnInitSuccessClientOnly  - If the SDK was initialized, but only client-side functionality is available, such as
        ///                                     calls to gfnStartStream. By definition, gfnIsRunningInCloud is expected to return false
        ///                                     in this scenario.
        /// @retval gfnUnableToAllocateMemory - SDK initialization failed due to lack of available memory, and no SDK functionality is
        ///                                     available.
        /// @retval gfnInitFailure            - SDK initialization failed for any other reason, and no SDK functionality is available.
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnInitializeRuntimeSdk(GfnDisplayLanguage displayLanguage);

        ///
        /// @par Description
        /// Releases the SDK, and frees up memory allocated by GFN and disconnects from GFN backend.
        ///
        /// @par Environment
        /// Cloud and Client
        ///
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call during application shutdown or when GFN Runtime API methods are no longer needed.
        NVGFNSDK_EXPORT void NVGFNSDKApi gfnShutdownRuntimeSdk();
        /// @}

        /// @defgroup callbacks Client Callback Registration
        /// Callback registration functions to receieve various messages / requests from the SDK.
        /// Register only after calling gfnInitializeRuntimeSdk().
        /// @{

        ///
        /// @par Description
        /// Register an application function to call when Geforce NOW needs to exit the game.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Register an application function to call when Geforce NOW needs to exit the game.
        ///
        /// @param exitCallback             - Function pointer to application code to call when Geforce NOW
        ///                                   needs to exit the game.
        /// @param pUserContext             - Pointer to user context, which will be passed unmodified to the
        ///                                   registered callback. Can be NULL.
        ///
        /// @retval gfnSuccess              - On success, when running in a Geforce NOW environment
        /// @retval gfnInternalError        - If callback could not be registered
        /// @retval gfnInvalidParameter     - If exitCallback function pointer is NULL.
        /// @retval gfnCallWrongEnvironment - If callback could not be registered since this function
        ///                                   was called outside of a cloud execution environment
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterExitCallback(ExitCallbackSig exitCallback, void* pUserContext);

        ///
        /// @par Description
        /// Register an application callback with Geforce NOW to be called when Geforce NOW
        /// needs to pause the game on the user's behalf. For Multiplayer games, it is
        /// recommended that this is implemented similar to a client disconnect.
        ///
        /// @par Environment
        /// Cloud
        ///
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register an application function to call when Geforce NOW needs to pause the game.
        ///
        /// @param pauseCallback            - Function pointer to application code to call when
        ///                                   Geforce NOW needs to pause the game
        /// @param pUserContext             - Pointer to user context, which will be passed unmodified to the
        ///                                   registered callback. Can be NULL.
        ///
        /// @retval gfnSuccess              - On success, when running in a Geforce NOW environment
        /// @retval gfnInternalError        - If callback could not be registered
        /// @retval gfnInvalidParameter     - If pauseCallback function pointer is NULL.
        /// @retval gfnCallWrongEnvironment - If callback could not be registered since this function
        ///                                   was called outside of a cloud execution environment
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterPauseCallback(PauseCallbackSig pauseCallback, void* pUserContext);

        ///
        /// @par Description
        /// Register an application callback with Geforce NOW to be called after a successful call to
        /// @ref gfnSetupTitle. Typically, the callback would handle any additional installation steps that
        /// are necessary after Geforce NOW performs its own setup for a given title.
        ///
        /// @par Environment
        /// Cloud
        ///
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register a function to call after a successful call to gfnSetupTitle.
        ///
        /// @param installCallback            - Function pointer to application code to call after
        ///                                     Geforce NOW successfully performs its own title setup.
        /// @param pUserContext               - Pointer to user context, which will be passed unmodified to the
        ///                                     registered callback. Can be NULL.
        ///
        /// @retval gfnSuccess                - On success, when running in a Geforce NOW environment
        /// @retval gfnInternalError        - If callback could not be registered
        /// @retval gfnInvalidParameter       - If installCallback function pointer is NULL.
        /// @retval gfnCallWrongEnvironment   - If callback could not be registered since this function
        ///                                   was called outside of a cloud execution environment
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterInstallCallback(InstallCallbackSig installCallback, void* pUserContext);
        /// @}

        ///
        /// @par Description
        /// Register a callback that gets called on the user's PC when the streaming session state changes
        ///
        /// @par Environment
        /// Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Register a function to call when stream status changes on the user's client PC
        ///
        /// @param streamStatusCallback         - Function pointer to application code to call after
        ///                                       the Geforce NOW streamer changes state
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       registered callback. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success, when running on the client PC
        /// @retval gfnCallWrongEnvironment     - If callback could not be registered since this function
        ///                                       was called outside of a client execution environment
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterStreamStatusCallback(StreamStatusCallbackSig streamStatusCallback, void* pUserContext);
        /// @}

        ///
        /// @par Description
        /// Register an application callback with GFN to be called when GFN needs the application
        /// to save user progress. It is recommended that this be implemented as an autosave if
        /// such a feature is supported by your application.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register an application function to call when GFN needs the application to save
        ///
        /// @param saveCallback                 - Function pointer to application code to call when GFN needs
        ///                                       the application to save
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       callback specified. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success when running in a GFN environment
        /// @retval gfnInternalError            - If callback was not registered
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterSaveCallback(SaveCallbackSig saveCallback, void* pUserContext);
        /// @}

        ///
        /// @par Description
        /// Register an application callback with GFN to be called when a GFN user has connected to the game seat
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register an application function to call when a GFN user has connected to the game seat
        ///
        /// @param sessionInitCallback          - Function pointer to application code to call when GFN is
        ///                                       ready for the application to finalize loading
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       callback specified. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success when running in a GFN environment
        /// @retval gfnInvalidParameter         - If callback was NULL
        /// @retval gfnCloudLibraryNotFound     - If the on-seat dll was not present (Usually due to not running on a seat)
        /// @retval gfnAPINotFound              - If the API was not found in the GFN SDK Library
        /// @retval gfnCallWrongEnvironment     - If the on-seat dll detected that it was not on a game seat
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterSessionInitCallback(SessionInitCallbackSig sessionInitCallback, void* pUserContext);
        /// @}

        ///
        /// @par Description
        /// Register an application callback with GFN to be called when a message is sent to the application.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Provide a callback function that will be called when a message is sent to the application.
        ///
        /// @param messageCallback              - Function pointer to application code to call when a message
        ///                                       has been recieved.
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       callback specified. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success when running in a GFN environment
        /// @retval gfnInvalidParameter         - If callback was NULL
        /// @retval gfnCloudLibraryNotFound     - If the on-seat dll was not present (Usually due to not running on a seat)
        /// @retval gfnAPINotFound              - If the API was not found in the GFN SDK Library
        /// @retval gfnCallWrongEnvironment     - If the on-seat dll detected that it was not on a game seat
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterMessageCallback(MessageCallbackSig messageCallback, void* pUserContext);
        ///
        /// @par Description
        /// Register an application callback with GFN to be called when certain client info that is part of @ref gfnGetClientInfo API changes
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register an application function to call when a the client information from the GFN user's client system has changed
        ///
        /// @param clientInfoCallback           - Function pointer to application code to call when client information has changed
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       callback specified. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success when running in a GFN environment
        /// @retval gfnInvalidParameter         - If callback was NULL
        /// @retval gfnCloudLibraryNotFound     - If the on-seat dll was not present (Usually due to not running on a seat)
        /// @retval gfnAPINotFound              - If the API was not found in the GFN SDK Library
        /// @retval gfnCallWrongEnvironment     - If the on-seat dll detected that it was not on a game seat
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterClientInfoCallback(ClientInfoCallbackSig clientInfoCallback, void* pUserContext);
        /// @}

        ///
        /// @par Description
        /// Register an application callback with GFN to be called when client latency changes
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        /// 
        /// @par Usage
        /// Register an application function to call when a the network latency from the GFN user's client system has changed
        ///
        /// @param networkStatusCallback        - Function pointer to application code to call when network latency has changed
        /// @param updateRateMs                 - The targeted rate at which callbacks should occur
        /// @param pUserContext                 - Pointer to user context, which will be passed unmodified to the
        ///                                       callback specified. Can be NULL.
        ///
        /// @retval gfnSuccess                  - On success when running in a GFN environment
        /// @retval gfnInvalidParameter         - If callback was NULL
        /// @retval gfnCloudLibraryNotFound     - If the on-seat dll was not present (Usually due to not running on a seat)
        /// @retval gfnAPINotFound              - If the API was not found in the GFN SDK Library
        /// @retval gfnCallWrongEnvironment     - If the on-seat dll detected that it was not on a game seat
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnRegisterNetworkStatusCallback(NetworkStatusCallbackSig networkStatusCallback, unsigned int updateRateMs, void* pUserContext);
        /// @}

        // ============================================================================================
        // Application -> Geforce NOW SDK communication
        // The application should call these methods at the appropriate locations.
        /// @defgroup launcher Launcher Application Methods
        /// The functions is this section are called from a launcher in either the appropriate
        /// cloud or client environment.
        /// @{

        ///
        /// @par Description
        /// Quickly determines if the calling application is running in GFN environment or not with a low
        /// security assurance, and without requiring process registration.
        ///
        /// @par Environment
        /// Cloud and Client
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to quickly determine whether to enable / disable any low-value GFN cloud environment
        /// specific application logic, for example, to block any calls to @ref gfnStartStream() to
        /// avoid an error, or to know if @ref gfnGetTitlesAvailable can be called without an error.
        ///
        /// @warning
        /// This API is meant to fill the need to quickly determine if the call looks to be in the
        /// GFN cloud environment. It purposefully trades off resource-intensive checks for fast response.
        /// Do not tie any logic or features of value to this API as the call stack could be tampered with.
        /// For that purpose, use @ref gfnIsRunningInCloudSecure.
        ///
        /// @retval true                        - Application is running on a GFN game seat virtual machine
        ///                                     in the Geforce NOW cloud.
        /// @retval false                       - Application is not running in the Geforce NOW cloud or in a
        ///                                     Geforce NOW test environment. This value will also be returned if
        ///                                     called before gfnInitializeRuntimeSdk().
        ///
        NVGFNSDK_EXPORT bool NVGFNSDKApi gfnIsRunningInCloud();

        ///
        /// @par Description
        /// Determines if calling application is running in GFN environment or not, and what degree of security assurance is
        /// assigned to the result.
        ///
        /// @par Environment
        /// Cloud and Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Call from an NVIDIA-approved process to securely determine whether running in GFN cloud, and use the
        /// GfnIsRunningInCloudAssurance value to decide the risk to enable any application specific logic
        /// for that environment.
        ///
        /// @warning
        /// This API must be called from a process that has been registered with NVIDIA, or it will return an error.
        /// Refer to the Cloud Check API Guide on how to get your application registered. To prevent
        /// man-in-the-middle (MiM) attacks, you must also securely load the SDK library, checking the integrity
        /// of the digital signature on the binary. Make sure to use the value returned from GfnIsRunningInCloudAssurance
        /// to decide if the check was certain enough without tampering to enable the logic or feature associated
        /// with the API call.
        ///
        /// @param assurance                 - Level of assurance that API is running in GFN cloud environment
        ///
        /// @retval gfnSuccess               - On success
        ///
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnIsRunningInCloudSecure(GfnIsRunningInCloudAssurance* assurance);

        ///
        /// @par Description
        /// Determines if a specific title is available to launch in current streaming session
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to determine if a title is available to be streamed from the active GFN cloud instance,
        /// for example, to show a "Play" button in a platform launcher's UI.
        ///
        /// @param pchPlatformAppId - Identifier of the requested title to check
        ///
        /// @retval true                        - Title is available for playing
        /// @retval false                       - Title is not available for playing. The common cases for this is the
        ///                                     title is not supported on GFN, or the GFN servers do not load every
        ///                                     supported game to every system in all cases.
        NVGFNSDK_EXPORT bool NVGFNSDKApi gfnIsTitleAvailable(const char* pchPlatformAppId);

        ///
        /// @par Description
        /// Retrieves all titles that can be launched in the current game streaming session
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to retrieve a list of all titles available to launch in the current streaming session,
        /// for example, to add "Play" buttons to all titles instead of calling gfnIsTitleAvailable on
        /// each title.
        ///
        /// @param ppchPlatformAppIds        - Comma-delimited list of platform identifiers. Memory
        ///                                    is allocated for the list. Call @ref gfnFree to release the memory when done.
        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @note
        /// To avoid leaking memory, call @ref gfnFree once done with the list
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetTitlesAvailable(const char** ppchPlatformAppIds);

        ///
        /// @par Description
        /// Notifies Geforce NOW that an application should be readied for launch. Geforce NOW
        /// will make the build files associated with the application available at the path
        /// returned in the SetupTitleResult struct passed in to the ConfirmTitleSetup callback
        /// provided by the caller. Additionally, Geforce NOW will set all necessary settings to
        /// optimize for the Geforce NOW cloud environment, and download any associated user data,
        /// including save files.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to prepare an application for launch on Geforce NOW, and block on the result.
        ///
        /// @param pchPlatformAppId - Identifier of the requested application to setup
        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @retval gfnSetupTitleFailure     - The Geforce NOW SDK failed to set up the title
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnSetupTitle(const char* pchPlatformAppId);

        ///
        /// @par Description
        /// Notifies GFN that an application has exited. GFN will then start the
        /// shutdown process for that application. Note that this is for use by
        /// platform clients only and assumes the application has already completed
        /// execution. To shutdown from within an application itself, gfnShutdownRuntimeSDK is used.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to notify GFN that your application has exited.
        ///
        /// @param pchPlatformId             - Identifier of the launcher service, e.g. "Steam"
        /// @param pchPlatformAppId          - Identifier of the application that has exited.
        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnTitleExited(const char* pchPlatformId, const char* pchPlatformAppId);

        ///
        /// @par Description
        /// Since applications running under Geforce NOW run in the Geforce NOW data centers,
        /// any IP queries made by the Application will return IPs associated
        /// with the data center, not the user's external client IP, as seen by Internet queries.
        /// This SDK call allows the application to obtain the user's client IP in the IPv4 format
        /// so that developers can make regional business decisions for the user based on it versus
        /// the region of the data center the user is connected to for game streaming sessions.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call this during application start or from the platform client in
        /// order to get the user's external client IP address.
        ///
        /// @param ppchClientIp              - Output IPv4 in string format. Example: "192.168.0.1".
        ///                                    Call @ref gfnFree to release the memory when done.
        ///
        /// @retval gfnSuccess               - Successfully retrieved client IP
        /// @retval gfnNoData                - No IP data found
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// The IP data returned by this API can be subject to various privacy laws depending on how the
        /// the data is used. To avoid the data being considered Personally Identifiable Information and
        /// subject to those laws, the IP should be used for geolocation lookup only and then discarded.
        /// @note
        /// To avoid leaking memory, call @ref gfnFree once done with the list
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetClientIp(const char** ppchClientIp);

        ///
        /// @par Description
        /// Gets user's client language code in the form "<lang>-<country>" using
        /// a standard ISO 639-1 language code and ISO 3166-1 Alpha-2 country code.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call this during application start or from the platform client in
        /// order to get the user's language and country settings.
        ///
        /// @param ppchLanguageCode          - Language code as a string. Example: "en-US".
        ///                                    Call @ref gfnFree to release the memory when done.
        ///
        /// @retval gfnSuccess               - Successfully retrieved language code
        /// @retval gfnNoData                - No language code found
        /// @retval gfnInvalidParameter      - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// To avoid leaking memory, call @ref gfnFree once done with the list
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetClientLanguageCode(const char** ppchLanguageCode);

        ///
        /// @par Description
        /// Gets user’s client country code using ISO 3166-1 Alpha-2 country code.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call this during application start or from the platform client in order to get
        /// the user's country code.
        ///
        /// @param pchCountryCode            - Country code as a 2 character string. Example: "US".
        /// @param length                    - Length of pchCountryCode character array, the length
        ///                                    should be at least 3
        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in or buffer length is too small
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetClientCountryCode(char* pchCountryCode, unsigned int length);
        ///
        /// @par Description
        /// Gets various information about the local client system and environment
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call this during application start or from the platform client in order to get
        /// various information about the client that launched the streaming session.
        ///
        /// @param clientInfo                - Pointer to a GfnClientInfo struct.

        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in or buffer length is too small
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// The client data returned by this function is best effort, as not all client devices will report
        /// all information. For example, certain browser and TV clients will not report client resolution or
        /// will incorrect resolution in certain situations. In the cases the data is not reported, the data
        /// returned will be zeroes. Likewise for safezone information, as most clients, such as Windows PC,
        /// do not have screen areas unsafe for rendering or input. For more information about safe zones,
        /// see the  the Mobile Integration Guide in the /doc folder.
        NVGFNSDK_EXPORT GfnRuntimeError gfnGetClientInfo(GfnClientInfo* clientInfo);

        ///
        /// @par Description
        /// Gets various information about the current streaming session
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Call this from a streaming session to find out more information about the session, such
        /// as session time remaining, or if RTX is enabled for the current session.
        ///
        /// @param sessionInfo               - Pointer to a GfnSessionInfo struct.

        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnInvalidParameter      - NULL pointer passed in or buffer length is too small
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// If the application has called @ref gfnRegisterSessionInitCallback to be notified when a
        /// user connects, then this API should be called after that callback is triggered.
        /// Certain data, such as session time limit or RTX support, can only be defined when a user
        /// connects as the values depend on the user type. Calling before that point can result in
        /// obtaining incorrect data.
        NVGFNSDK_EXPORT GfnRuntimeError gfnGetSessionInfo(GfnSessionInfo* sessionInfo);

        ///
        /// @par Description
        /// Requests GFN client to start a streamed session of an application in an asynchronous fashion
        ///
        /// @par Environment
        /// Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Use to start a streaming session.
        ///
        /// @param pStartStreamInput            - Pointer to a StartStreamInput structure.
        /// @param cb                           - A StartStreamCallbackSig callback to be called with streaming events.
        /// @param context                      - User context
        /// @param timeoutMs                    - Time after which attempt to start streaming will be aborted.
        NVGFNSDK_EXPORT void NVGFNSDKApi gfnStartStreamAsync(const StartStreamInput * pStartStreamInput, StartStreamCallbackSig cb, void* context, unsigned int timeoutMs);

        ///
        /// @par Description
        /// Requests GFN client to start a streamed session of an application in a synchronous (blocking) fashion.
        ///
        /// @par Environment
        /// Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Use to start a streaming session.
        ///
        /// @param pStartStreamInput        - Pointer to a StartStreamInput structure.
        /// @param response                 - Start streaming response.
        ///
        /// @retval gfnSuccess              - On success
        /// @retval gfnInvalidParameter     - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment - If called in a cloud environment
        /// @retval gfnStreamFailure        - Network failure or other error prevented the stream from starting
        /// @retval gfnCanceled             - User canceled the download and install of GFN client during stream initialization
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnStartStream(StartStreamInput* pStartStreamInput, StartStreamResponse* response);

        ///
        /// @par Description
        /// Requests GFN client to stop the active streaming session of an application in a synchronous (blocking) fashion.
        ///
        /// @par Environment
        /// Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Use to request the streaming session be stopped
        ///
        /// @retval gfnSuccess              - On success
        /// @retval gfnStreamStopFailure    - Failure to stop the streaming session
        /// @retval gfnCallWrongEnvironment - If called in a cloud environment
        /// @retval gfnStreamFailure        - Network failure or other error prevented the stream from starting
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnStopStream(void);

        ///
        /// @par Description
        /// Requests GFN client to stop the active streaming session of an application in aynchronous fashion.
        ///
        /// @par Environment
        /// Client
        /// 
        /// @par Platform
        /// Windows
        ///
        /// @par Usage
        /// Use to request the streaming session be stopped
        ///
        /// @param cb                           - A StartStreamCallbackSig callback to be called with streaming events.
        /// @param context                      - User context
        /// @param timeoutMs                    - Time after which attempt to stop streaming and associated processed to close will be aborted.
        ///                                       A value of 0 signals to immediately return without waiting for processes to close.
        NVGFNSDK_EXPORT void NVGFNSDKApi gfnStopStreamAsync(StopStreamCallbackSig cb, void* context, unsigned int timeoutMs);

        ///
        /// @par Description
        /// Retrieves non-secure partner data that is either a) passed by the client in the gfnStartStream call or b) sent using Deep Link parameter.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use during cloud session to retrieve partner data based in during session initialization.
        ///
        /// @param ppchPartnerData          - Populated with the partner data in string form if found
        ///                                   Call @ref gfnFree to release the memory when done with data
        ///
        /// @retval gfnSuccess              - Partner data successfully retrieved from session data
        /// @retval gfnNoData               - No partner data found in session data
        /// @retval gfnInvalidParameter     - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment - Called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// To avoid leaking memory, call @ref gfnFree once done with the data
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetPartnerData(const char** ppchPartnerData);

        ///
        /// @par Description
        /// Retrieves secure partner data that is either a) passed by the client in the gfnStartStream call or b) sent in response to Deep Link nonce validation.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use during cloud session to retrieve secure partner data
        ///
        /// @param ppchPartnerSecureData     - Populated with the secure partner data in string form if found
        ///                                    Call @ref gfnFree to release the memory when done.
        ///
        /// @retval gfnSuccess               - Secure partner data successfully retrieved from session data
        /// @retval gfnNoData                - No secure partner data found in session data
        /// @retval gfnInvalidParameter      - NULL pointer passed in
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        /// @return Otherwise, appropriate error code
        /// @note
        /// To avoid leaking memory, call @ref gfnFree once done with the list
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnGetPartnerSecureData(const char** ppchPartnerSecureData);

        ///
        /// @par Description
        /// Releases memory allocated by Get functions such as, but not limited to, @ref gfnGetPartnerData,
        /// @ref gfnGetPartnerSecureData, or @ref gfnGetTitlesAvailable
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to release memory after a call to a memory-allocated function and you are finished with the data.
        /// Should only be called if the memory is populated with valid data. Calling @ref gfnFree with invalid
        /// pointer or data will result in an memory exception being thrown.
        ///
        /// @param ppchData                  - Pointer to allocated string memory
        ///
        /// @retval gfnSuccess               - Memory successfully released
        /// @retval gfnInvalidParameter      - Invalid pointer or data passed in
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnFree(const char** ppchData);


        ///
        /// @par Description
        /// Notifies GFN that an application is ready to be displayed.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to notify GFN that your application is ready to be displayed.
        ///
        /// @param success             - True if startup has succeeded
        /// @param status              - Optional status of startup operations
        ///
        /// @retval gfnSuccess               - On success
        /// @retval gfnCallWrongEnvironment  - If called in a client environment
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnAppReady(bool success, const char * status);

        ///
        /// @par Description
        /// Defines active zone coordinates for GFN to interact with.
        ///
        /// @par Environment
        /// Cloud
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to invoke special events on the client from the GFN cloud environment
        ///
        /// @param type                 - Populated with relevant GfnActionType
        /// @param id                   - unique unsigned int type identifier for this action zone
        /// @param zone                 - To enable action zone set this parameter to GfnRect coordinates of the zone, to disable action zone set this parameter to NULL
        ///
        /// @retval gfnSuccess              - Call was successful
        /// @retval gfnInputExpected        - Expected zone to have a value
        /// @retval gfnComError             - There was SDK internal communication error
        /// @retval gfnInitFailure          - SDK was not initialized
        /// @retval gfnInvalidParameter     - Invalid parameters provided
        /// @retval gfnThrottled            - API call was throttled for exceeding limit
        /// @retval gfnUnhandledException   - API ran into an unhandled error and caught an exception before it returned to client code
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError NVGFNSDKApi gfnSetActionZone(GfnActionType type, unsigned int id, GfnRect* zone);

        ///
        /// @par Description
        /// Sends a custom message communication from the app to the client. This message
        /// is "fire-and-forget", and does not wait for the message to be delivered to return status.
        /// Latency is best effort and not guaranteed.
        ///
        /// @par Environment
        /// Cloud or Client
        /// 
        /// @par Platform
        /// Windows, Linux
        ///
        /// @par Usage
        /// Use to communicate between cloud applications and streaming clients.
        ///
        /// @param pchMessage - Character string
        /// @param length     - Length of pchMessage in characters, which cannot exceed 8K in length
        ///
        /// @retval gfnSuccess              - Call was successful
        /// @retval gfnComError             - There was SDK internal communication error
        /// @retval gfnInitFailure          - SDK was not initialized
        /// @retval gfnInvalidParameter     - Invalid parameters provided, or message exceeded allowed length
        /// @retval gfnThrottled            - API call was throttled for exceeding limit of 30 messages per second
        /// @retval gfnUnhandledException   - API ran into an unhandled error and caught an exception before it returned to client code
        /// @retval gfnCloudLibraryNotFound - GFN SDK cloud-side library could not be found
        /// @return Otherwise, appropriate error code
        NVGFNSDK_EXPORT GfnRuntimeError gfnSendMessage(const char* pchMessage, unsigned int length);

        /// @}
#ifdef __cplusplus
    } // extern "C"
#endif


#endif // GFN_SDK_RUNTIME_CAPI_H

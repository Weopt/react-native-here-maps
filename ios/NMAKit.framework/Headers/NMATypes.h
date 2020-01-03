/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * The Common group includes classes, protocols, and enumerations
 * that are generally used by other packages in the iOS SDK.
 * Some important classes in this group are `NMAGeoCoordinates`
 * and `NMAPositioningManager`.
 */

/**
 * The minimum Z Index for an `NMAMapObject`
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMinimumZIndex;

/**
 * The maximum Z Index for an `NMAMapObject`
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMaximumZIndex;


/**
 * Lower limit of the `NMAMapView.zoomLevel` property.
 */
FOUNDATION_EXPORT const float NMAMapViewMinimumZoomLevel;

/**
 * Upper limit of the `NMAMapView.zoomLevel` property.
 */
FOUNDATION_EXPORT const float NMAMapViewMaximumZoomLevel;

/**
 * Represents fixed locations or regions within a bounding rectangle.
 */
typedef NS_ENUM(NSUInteger, NMALayoutPosition) {
    NMALayoutPositionTopLeft,
    NMALayoutPositionTopCenter,
    NMALayoutPositionTopRight,
    NMALayoutPositionCenterLeft,
    NMALayoutPositionCenter,
    NMALayoutPositionCenterRight,
    NMALayoutPositionBottomLeft,
    NMALayoutPositionBottomCenter,
    NMALayoutPositionBottomRight
};

/**
 * Error codes that may be returned from places search requests.
 */
typedef NS_ENUM(NSUInteger, NMARequestError) {
    /// No error.
    NMARequestErrorNone = 0,
    /// Unknown error.
    NMARequestErrorUnknown,
    /// Request is missing an address parameter.
    NMARequestErrorAddressMissing,
    /// Location context is invalid.
    NMARequestErrorLocationContextInvalid,
    /// Request is missing location context parameter.
    NMARequestErrorLocationContextMissing,
    /// Request is missing a country code in the address parameter.
    NMARequestErrorCountryCodeMissing,
    /// Request missing search text parameter.
    NMARequestErrorSearchTextMissing,
    /// Invalid query parameter.
    NMARequestErrorInvalidParameter,
    /// Network communications error.
    NMARequestErrorNetworkCommunication,
    /// Backend server unreachable.
    NMARequestErrorNetworkServer,
    /// Request input missing.
    NMARequestErrorNetworkEmptyInput,
    /// Application ID and/or token are missing or invalid.
    NMARequestErrorInvalidCredentials,
    /// Request failed due to an HTTP error.
    NMARequestErrorHttp,
    /// Unknown network error.
    NMARequestErrorNetworkUnknown,
    /// Functionality not supported.
    NMARequestErrorNotSupported,
    /**
     * An entity is not ready. All poll functions return this when one needs to
     * poll again. Also if an operation is in progress.
     */
    NMARequestErrorNotReady,
    /// When something was not found.
    NMARequestErrorNotFound,
    /// When resource already exists.
    NMARequestErrorAlreadyExists,
    /// Out of memory.
    NMARequestErrorOutOfMemory,
    /// When operation fails (e.g.extracting of file failed).
    NMARequestErrorOperationFailed,
    /// Operation aborted by user.
    NMARequestErrorAborted,
    /// Search index failure.
    NMARequestErrorFinderIndexFailure,
    /// Resource moved (e.g. resource URI changed).
    NMARequestErrorMovedPermanently,
    /// Resource contend remains the same.
    NMARequestErrorNotModified,
    /// Invalid request (places component might need to be updated).
    NMARequestErrorBadRequest,
    /// Resource no longer exists.
    NMARequestErrorResourceGone,
    /// An error occured during document parsing (json, etc.).
    NMARequestErrorParse,
    /// Request timeout.
    NMARequestErrorTimeout
};

/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Normal scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalDay;

/**
 * Normal scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeNormalNight;

/**
 * Normal scheme presented in "day" with less color palette.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeReducedDay;

/**
 * Normal scheme presented in "night" with less color palette.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeReducedNight;

/**
 * Terrain bitmap scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeTerrainDay;

/**
 * Satellite tile scheme presented in "day" colors.
 *
 * @note No roads are shown. For satellite and roads use `NMAMapSchemeHybridDay`
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeSatelliteDay;

/**
 * Satellite tile scheme presented in "day" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemeHybridDay;

/**
 * Pedestrian navigation scheme presented in "day" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features
 * on the map view.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemePedestrianDay;

/**
 * Pedestrian navigation scheme presented in "night" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features
 *on the map view.
 */
FOUNDATION_EXPORT NSString *const NMAMapSchemePedestrianNight;

/**
 * Represents a collection of schemes that a `NMAMapView` supports.
 * Each of the schemes in this class can be set by way of the
 * `NMAMapView.mapScheme` property.
 */
@interface NMAMapScheme : NSObject

/**
 * Determines whether the specified scheme is supported (is valid for the
 * application).
 *
 * @param scheme A `NSString` representing the scheme to check
 * @return YES if the scheme is valid, NO otherwise
 */
+ (BOOL)isValid:(NSString *)scheme;

@end

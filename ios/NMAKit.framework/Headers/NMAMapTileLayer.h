/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMATypes.h"

@class NMAMapTileLayer;
@class NMAGeoBoundingBox;

/**
 * An interface for providing tile bitmap data to an `NMAMapTileLayer` instance.
 *
 * @note The methods of this protocol will be called on an internal NMA map rendering queue.
 * Blocking this queue for extended periods of time will adversely effect map rendering
 * performance.
 */
@protocol NMAMapTileLayerDataSource <NSObject>

@optional



/**
 * Indicates if the specified tile should be rendered.
 *
 * If this method returns NO then a further call to request tile bitmap data or tile URL will
 * not be made. Not implementing this protocol method is equivalent to returning YES.
 *
 * At each zoomLevel the framework expects the "world" to be rendered on (2^zoomLevel)^2 tiles.
 *
 * The x and y parameters indicate which tile is being requested for the given zoom level:
 *
 * - At zoom level 3 the framework will ask you for 8 x 8 tiles
 *
 * - At zoom level 4 the framework will ask you for 16 x 16 tiles
 *
 * - ...
 *
 * @param mapTileLayer `NMAMapTileLayer` instance that is requesting the tile.
 * @param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param zoomLevel Zoom level of the tile being requested in the range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the `NMAMapView` to which the `NMAMapTileLayer` has been added.
 *
 * @return YES if the requested tile should be rendered, NO otherwise.
 *
 * @note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 */
- (BOOL)mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
          hasTileAtX:(NSUInteger)x
                   y:(NSUInteger)y
           zoomLevel:(NSUInteger)zoomLevel;

/**
 * Returns a URL from which the tile bitmap can be downloaded
 *
 * Implement this method if you wish to have the framework download tile bitmap data from a URL
 * you provide. This method will be called whenever the map view needs bitmap data to render the
 * specified tile.
 *
 * This method is provided as a convenience for the common case of downloading bitmaps tiles
 * from a URL. The data returned from the URL must be in either png and jpg format.
 *
 * See `-mapTileLayer:hasTileAtX:y:zoomLevel:` for a detailed description of the x, y and zoomLevel parameters.
 *
 * @note This method will not be called if you also implement `-mapTileLayer:requestTileAtX:y:zoomLevel:`
 * or `-mapTileLayer:requestTileAtX:y:zoomLevel:`
 *
 * @note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 *
 * @param mapTileLayer NMAMapTileLayer instance that is requesting the tile URL.
 * @param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param zoomLevel Zoom level of the tile being requested in the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the NMAMapView to which the NMAMapTileLayer has been added.
 *
 * @return URL to fetch the requested tile from.
 */
- (nonnull NSString *)mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
                     urlForTileAtX:(NSUInteger)x
                                 y:(NSUInteger)y
                         zoomLevel:(NSUInteger)zoomLevel;

/**
 * Requests raw tile bitmap data for the specified tile.
 *
 * Implement this method if you wish to supply raw tile bitmap data. This method will be called
 * whenever the map view needs bitmap data to render the specified tile.
 *
 * See `-mapTileLayer:hasTileAtX:y:zoomLevel:` for a detailed description of the x, y and
 * zoomLevel parameters.
 *
 * Implementing this method will prevent `-mapTileLayer:urlForTileAtX:y:zoomLevel:` and
 * `-mapTileLayer:requestTileAtX:y:zoomLevel:` from being called.
 *
 * @note This method is called on an internal NMA map rendering queue. Blocking for extended
 * periods of time will impact map rendering performance.
 *
 * @param mapTileLayer `NMAMapTileLayer` instance that is requesting the tile bitmap.
 * @param x X coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param y Y coordinate of the tile being requested in the range 1..(2^zoomLevel).
 * @param zoomLevel Zoom level of the tile being requested in the range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`.
 *                  The zoomLevel parameter value may NOT have the same value as the zoomLevel property of
 *                  the `NMAMapView` to which the `NMAMapTileLayer` has been added.
 *
 * @return Raw tile bitmap data.
 */
- (nonnull NSData *) mapTileLayer:(nonnull NMAMapTileLayer *)mapTileLayer
            requestDataForTileAtX:(NSUInteger)x
                                y:(NSUInteger)y
                        zoomLevel:(NSUInteger)zoomLevel;

@end

/**
 * A layer of custom raster tiles for display in an `NMAMapView`.
 *
 * Raster tiles are supplied as bitmap data and can be supplied synchronously
 * or simply by providing a URL from which to download the tiles from.
 *
 * To use this class create an instance, configure the properties and call
 * `-[NMAMapView addMapTileLayer]`.
 *
 * @note IMPORTANT! The properties of this interface should not be modified after the instance
 * has been added to an `NMAMapView`. See the `NMAMapTileLayer.locked` property.
 */
@interface NMAMapTileLayer : NSObject

/**
 * Data source that provides tile bitmap data for the `NMAMapTileLayer`
 *
 * @note This property cannot be set when the instance is locked. See `NMAMapTileLayer.locked`.
 */
@property (nullable, nonatomic, weak) id<NMAMapTileLayerDataSource> dataSource;

/**
 * Indicates if the tile layer is locked.
 *
 * The tile layer is locked when it is added to an `NMAMapView` instance. While the tile layer
 * is locked attempts to set any properties will be ignored. The tile layer is unlocked when
 * it is removed from an `NMAMapView` instance.
 */
@property (nonatomic, readonly, getter = isLocked) BOOL locked;

/**
 * Specifies the Z-index (stacking order) for the bitmap tiles within the map layer
 * specified by the mapLayerType property.
 *
 * All objects within a map layer have a Z-index associated with them. Objects with the highest
 * value are placed at the top of the stacking order. If two or more objects within a map layer
 * have the same z-index value the their stacking order is undefind.
 *
 * Z-index values range from `NMAMapObjectMinimumZIndex` to `NMAMapObjectMaximumZIndex`. The property
 * will be clamped to this range if invalid values are specified.
 *
 * This property defaults to `NMAMapObjectMinimumZIndex`.
 *
 * @note This property cannot be set when the instance is locked. See `NMAMapTileLayer.locked`.
 */

@property (nonatomic) NSUInteger zIndex;

/**
 * Specifies the `NMAGeoBoundingBox` within which tiles will be requested and rendered.
 *
 * Tiles falling fully outside the boundingBox will not be requested.
 *
 * This property defaults to an unbounded value - i.e. tiles are rendered across the world.
 *
 * @note This property cannot be set when the instance is locked. See `NMAMapTileLayer.locked`.
 */
@property (nullable, nonatomic) NMAGeoBoundingBox *boundingBox;

/**
 * Specifies whether tile bitmaps will be cached to disk by the framework.
 *
 * File system caching is provided as a convenience. If caching is enabled tiles will not
 * be re-requested via `NMAMapTileLayerDelegate` until they have expired.
 *
 * This property defaults to NO. Caching is enabled by calling `setCacheEnabled:withIdentifier:`.
 */
@property (nonatomic, readonly, getter = isCacheEnabled) BOOL cacheEnabled;

/**
 * Identifier used to associate disk cached tile data with a `NMAMapTileLayer` instance
 * to prevent clashes in the cache folder.
 *
 * You must use unique cache identifiers to ensure there will be no filename clashes in the
 * cache folder structure. It also allows you to easily identify the cache in the filesystem.
 *
 * This property is set when you enable caching. See `setCacheEnabled:withIdentifier:`.
 */
@property (nullable, nonatomic, readonly) NSString *cacheIdentifier;

/**
 * Specifies the cache expiration time in seconds.
 *
 * Tile bitmaps will expire cacheTimeToLive seconds after they have been
 * downloaded causing them to be re-requested via `NMAMapTileLayerDataSource`
 * when the map needs to render them.
 *
 * This property defaults to 0 which means the cached tiles never expire.
 *
 * @note This property has no effect if the cacheEnabled property is set to NO.
 * Negative values will be reset to 0.
 */
@property (nonatomic) NSTimeInterval cacheTimeToLive;

/**
 * Specifies the maximum size the cache will consume on disk.
 *
 * The framework may allow the cache size to grow an additional 5MB to the size
 * specified in order to reduce disk access.
 *
 * This property defaults to 0 which means the cache size is not limited.
 *
 * @note This property has no effect if the cacheEnabled property is set to NO.
 * Also, this property cannot be set when the instance is locked. See `NMAMapTileLayer.locked`.
 */
@property (nonatomic) NSUInteger cacheSizeLimit;

/**
 * Enable/Disable caching of tile data to disk.
 *
 * File system caching is provided as a convenience. If caching is enabled tiles will not
 * be re-requested via `NMAMapTileLayerDelegate` until they have expired.
 *
 * It's important to always use the same cache identifier for your tile data. Otherwise,
 * multiple disassociated cache folders will be created in the file system. This wastes disk
 * space, and you will not benefit from persistent disk caching across sessions.
 *
 * @note Calling this method changes the values of the cacheEnabled and cacheIdentifier
 * properties.
 *
 * @param enabled YES to enable caching, NO to disable.
 * @param identifier You must use a unique cache identifier to ensure there will be no filename
 *                   clashes in the cache folder structure. Passing a nil or empty string
 *                   will result in caching NOT being enabled. The identifier is set the first time
 *                   you call this method and will not be changed by subsequent calls to this method
 *                   for the lifetime of the instance. If the identifier you supply contains
 *                   non alphanumeric characters they will be stripped from the identifier, with the
 *                   exception of "_" and "-".
 */
- (void)setCacheEnabled:(BOOL)enabled withIdentifier:(nonnull NSString *)identifier
NS_SWIFT_NAME(setCache(enabled:identifier:));

/**
 * Clears the file system cache identified by the cacheIdentifier property.
 *
 * @note To guarantee the cache is cleared this method should be called after the
 * NMAMapTileLayer instance has been removed from the NMAMapView
 */
- (void)clearCache;

/**
 * Shows the raster tiles at the specified zoom level.
 *
 * You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.
 *
 * @note This method does nothing when the instance is locked. See `NMAMapTileLayer.locked`.
 *
 * @param zoomLevel Zoom level at which to show the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 */
- (void)showAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(show(atZoomLevel:));

/**
 * Hides the raster tiles at the specified zoom level.
 *
 * You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.
 *
 * @note This method does nothing when the instance is locked. See `NMAMapTileLayer.locked`.
 *
 * @param zoomLevel Zoom level at which to hide the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 */
- (void)hideAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(hide(atZoomLevel:));

/**
 * Shows the raster tiles at the specified zoom level range.
 *
 * You can control the tile visibility for each zoom level independently. For example, tiles
 * may be visible at levels 0, 5, 7 only. Tiles are shown at all zoom levels by default.
 *
 * The method will do nothing if ANY parameters fall outside the range
 * `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` or if fromLevel > toLevel.
 *
 * @note This method does nothing when the instance is locked. See `NMAMapTileLayer.locked`.
 *
 * @param fromLevel Lower zoom level index at which to show the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 * @param toLevel   Upper zoom level index at which to show the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 */
- (void)showFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel
NS_SWIFT_NAME(show(fromZoomLevel:toZoomLevel:));

/**
 * Hides the raster tiles at the specified zoom level range.
 *
 * You can control the tile visibility for each zoom level independently. This method allows you
 * set the visibility for a range of zoom levels in one call.  Tiles are shown at all zoom levels
 * by default.
 *
 * The method will do nothing if ANY parameters fall outside the range
 * `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` or if fromLevel > toLevel.
 *
 * @note This method does nothing when the instance is locked. See `NMAMapTileLayer.locked`.
 *
 * @param fromLevel Lower zoom level index at which to hide the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 * @param toLevel   Upper zoom level index at which to hide the tiles. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will be ignored
 */
- (void)hideFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel
NS_SWIFT_NAME(hide(fromZoomLevel:toZoomLevel:));

/**
 * Returns whether tiles are visisble at the specified zoom level
 *
 * You can control the tile visibility for each zoom level independently. This method allows you
 * set the visibility for a range of zoom levels in one call.  Tiles are shown at all zoom levels
 * by default.
 *
 * @param zoomLevel Zoom level. Values outside the range
 *                  `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel` will return NO.
 *
 * @return YES if tiles are shown at the specified zoom level, NO otherwise
 */
- (BOOL)isShownAtZoomLevel:(int)zoomLevel
NS_SWIFT_NAME(isShown(atZoomLevel:));

@end

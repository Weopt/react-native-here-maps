/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>
#import "NMATypes.h"
#import <GLKit/GLKit.h>
#import <OpenGLES/EAGL.h>
#import "NMAMapGesture.h"

@class NMAMapObject;
@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAMapView;
@class NMAMapTileLayer;
@class NMAPositionIndicator;

/**
 * The Mapping group provides classes, protocols, and enumerations that
 * can be used to enable an interactive map and
 * related functionality, such as creating and adding map objects.
 * Some key classes and protocols in this group are:
 * `NMAMapView`, `NMAMapGestureDelegate`,
 * `NMAMapObject` and `NMAMapScheme`
 */

/**
 * This value may be passed into the map move method
 * NMAMapView::setGeoCenter:zoomLevel:withAnimation:
 * in place of zoom in order to preserve the current value of that property.
 *
 * See also `NMAMapView::setGeoCenter:zoomLevel:withAnimation:`
 */
FOUNDATION_EXPORT const float NMAMapViewPreserveValue;

/**
 * Defines types of animations that can illustrate on-screen map movements.
 */
typedef NS_ENUM(NSUInteger, NMAMapAnimation) {
    /** Animation moves in a linear manner as the map resets to a new position. */
    NMAMapAnimationLinear,
    /** No animation is performed as the map resets to a new position. */
    NMAMapAnimationNone
};

/**
 * Defines PPI of the map tiles.
 */
typedef NS_ENUM(NSUInteger, NMAMapPPI) {
    /** Default PPI, suitable for mobile devices. */
    NMAMapPPILow,
    /** High PPI. */
    NMAMapPPIHigh,
    /** Internal use only */
    NMAMapPPIReserved
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a delegate that offers listeners and callback methods related to
 * visible actions that result from user interaction.
 *
 * @note Methods of this protocol are called on the main queue.
 */
@protocol NMAMapViewDelegate<NSObject>

@optional



/**
 * A callback indicating that `NMAMapObject` map objects have been
 * selected.
 *
 * @param mapView The `NMAMapView` instance sending the callback
 * @param objects A `NSArray` of selected map objects
 */
- (void)mapView:(NMAMapView *)mapView didSelectObjects:(NSArray<__kindof NMAMapObject *> *)objects
NS_SWIFT_NAME(mapViewDidSelectObjects(_:objects:));

/**
 * A callback indicating that a map movement has begun due to user
 * interaction.
 *
 * @note This callback will be sent at the start of the gesture when the map is
 * panned or pinch zoomed(only for user gestures).
 *
 * @note If the map receives more than one of these gestures at the same time,
 * only a single callback will be sent until all map movement has stopped.
 */
- (void)mapViewDidBeginMovement:(NMAMapView *)mapView;

/**
 * A callback indicating that a map movement has ended.
 *
 * @note There will be a one-to-one correspondence with this callback and the
 * `-mapViewDidBeginMovement:` callback.
 */
- (void)mapViewDidEndMovement:(NMAMapView *)mapView;

/**
 * A callback indicating the beginning of an animation on the map.
 *
 * Note that this callback is invoked after one of the following operations starts:
 *
 * - setting the map center (with animation), for exmaple with
 * `-[NMAMapView setGeoCenter:zoomLevel:withAnimation:]` or `-[NMAMapView setGeoCenter:withAnimation:]`
 *
 * - setting the map zoom level (with animation). E.g. with `-[NMAMapView setZoomLevel:withAnimation:]`
 */
- (void)mapViewDidBeginAnimation:(NMAMapView *)mapView;

/**
 * A callback indicating the end of an animation on the map.
 *
 * This is fired after one of the following operations ends:
 *
 * - setting the map center (with animation), for exmaple with
 * `-[NMAMapView setGeoCenter:zoomLevel:withAnimation:]` or `-[NMAMapView setGeoCenter:withAnimation:]`
 *
 * - setting the map zoom level (with animation). E.g. with `-[NMAMapView setZoomLevel:withAnimation:]`
 */
- (void)mapViewDidEndAnimation:(NMAMapView *)mapView;

/**
 * A callback indicating that map data has been drawn.
 */
- (void)mapViewDidDraw:(NMAMapView *)mapView;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

/**
 * A UIView subclass used by an application to display a geographical map.
 */
@interface NMAMapView : UIView

#pragma mark - New APIs

@property (nonatomic) BOOL useHighResolutionMap;
@property (nonatomic) NMAMapPPI mapPPI;

#pragma mark Setup

/**
 * Used to control the default `NMAMapView` rendering behaviour.
 *
 * This class method is used to set whether or not instances of `NMAMapView` will
 * begin rendering immediately upon creation. Any map view created after passing
 * NO to this method must have its renderAllowed property set to YES to begin
 * rendering.
 */
+ (void)shouldBeginRenderingAutomatically:(BOOL)enabled;

#pragma mark Behavior

/**
 * A flag which can be used to allow or disallow map rendering.
 *
 * @note Setting renderAllowed to NO guarantees that the map will not draw
 * again (but it will finish if a frame is in the middle of rendering), but
 * the map may not redraw with renderAllowed set to YES if it is prevented
 * from drawing for another reason.
 *
 * @note The map can be hinted to redraw (if allowed) by calling `setNeedsDisplay`.
 */
@property (nonatomic, getter = isRenderAllowed) BOOL renderAllowed;

/**
 * An event handler for the `NMAMapView`.
 *
 * An object may be installed as the `NMAMapView`'s delegate in order to respond
 * to certain map events, such as object selection or map movement. See the
 * `NMAMapViewDelegate` protocol for the full list of events.
  */
@property (nullable, nonatomic, weak) id<NMAMapViewDelegate> delegate;

#pragma mark Appearance

/**
 * The `NMAGeoBoundingBox` representing the current screen area of the
 * `NMAMapView`.
 *
 * The boundingBox of the map is the smallest possible `NMAGeoBoundingBox` which
 * contains all of the map area currently visible on the screen.
 *
 * @note The bounding box may be slightly inaccurate if the method is
 * invoked while the map is moving.
 *
 * @note If `padding` is used, screen position and bounding box will be
 * adjusted accordingly.
 */
@property (nonatomic, readonly, copy) NMAGeoBoundingBox *boundingBox;

/**
 * The scheme for the `NMAMapView`.
 *
 * See NMAMapScheme for supported schemes.
 */
@property (nonatomic, strong) NSString *mapScheme;

/**
 * The position indicator for the `NMAMapView`.
 */
@property (nonatomic, readonly) NMAPositionIndicator *positionIndicator;

#pragma mark Gestures

/**
 * An optional delegate to receive gestures events.
 *
 * See also `NMAMapGestureDelegate`
 */
@property (nullable, nonatomic, weak) id<NMAMapGestureDelegate> gestureDelegate;

/**
 * Indicates the state of enabling and modifying map gesture interaction
 * for the `NMAMapView`.
 *
 * If enabled, gesture handlers can be enabled to begin gesture handling. If
 * disabled, all gesture handling is disabled and the gesture handler state
 * cannot be modified.
 */
@property (nonatomic, getter = isMapInteractionEnabled) BOOL mapInteractionEnabled;

/**
 * The touch duration required to trigger a long press gesture.
 *
 * @note The default value is 1 second.
 */
@property (nonatomic) NSTimeInterval longPressDuration;

/**
 * Indicates the kinetic panning behaviour of the `NMAMapView`.
 *
 * When kinetic panning is enabled, at the conclusion of a pan gesture (when the user's
 * finger is removed from the device), the map will continue moving in the direction
 * and with the speed of the original pan before gradually coming to a stop.
 */
@property (nonatomic, getter = isKineticPanningEnabled) BOOL kineticPanningEnabled;

/**
 * Indicates whether the transform center is used on zoom gestures.
 *
 * By default disabled. If enabled, zoom will always be applied using
 * the current transform center, instead of a point relative the touch interaction.
 * See the transformCenter property.
 *
 * @note The transform center is usually the same as the screen's geometric center,
 * except in cases where it makes sense to have it slightly modified (example: in
 * guidance mode, the transform center is lowered a bit so that the route ahead
 * is more visible in the map view).
 */
@property (nonatomic) BOOL mapCenterFixedOnZoom;

/**
 * Enable one or more `NMAMapView` gestures.
 *
 * @param gestures A bit-mask combination of one or more `NMAMapGestureType` values.
 *
 * @note All gestures are enabled by default.
 *
 * @note Pass `NMAMapGestureTypeAll` to enable all gestures.
 */
- (void)enableMapGestures:(NSUInteger)gestures;

/**
 * Disable one or more `NMAMapView` gestures.
 *
 * @param gestures A bit-mask combination of one or more `NMAMapGestureType` values.
 *
 * @note Pass `NMAMapGestureTypeAll` to disable all gestures.
 *
 * @note Disabling a gesture type will also disable that type for the `NMAMapView`'s
 * gestureDelegate.
 */
- (void)disableMapGestures:(NSUInteger)gestures;

/**
 * Queries whether or not a gesture type is enabled on the `NMAMapView`.
 *
 * @param gesture The gesture type to query.
 */
- (BOOL)isMapGestureEnabled:(NMAMapGestureType)gesture;

#pragma mark Transformation

/**
 * The `NMAGeoCoordinates` of the world location corresponding to the
 * current screen position of the transformCenter.
 *
 * @note If `padding` is used, screen position and center will be adjusted
 * accordingly.
 */
@property (nonatomic) NMAGeoCoordinates *geoCenter;

/**
 * The padding on the map.
 *
 * Allows you to specify custom padding, in points. Use this property to define
 * invisible area of the map around `NMAMapView`. Map functions such as `zoom` and
 * `center` will be adapted to the padding.
 *
 * The `padding` values should not be less than 0. Sum of left and right padding
 * should not be higher than map width. Sum of top and bottom padding should not
 * be higher than map height. Invalid padding values will be kept but not applied
 * until map size is sufficient for them.
 *
 * The default padding values are {0, 0, 0, 0}.
 *
 * @note Developer must not use `transformCenter` and `padding` at the same time as the
 * only one of them will be taken into account, depending on the order of invocation.
 */
@property (nonatomic) UIEdgeInsets padding;

/**
 * The zoom level for the `NMAMapView`.
 *
 * @note Values must be in the range [`NMAMapViewMinimumZoomLevel`,
 * `NMAMapViewMaximumZoomLevel`]; invalid values will be clamped to this
 * range.
 */
@property (nonatomic) float zoomLevel;

#pragma mark Copyright

/**
 * The copyright logo position for the `NMAMapView`.
 *
 * @note Valid values are `NMALayoutPositionTopLeft`, `NMALayoutPositionTopCenter`,
 * `NMALayoutPositionTopRight`, `NMALayoutPositionBottomLeft`, `NMALayoutPositionBottomCenter`,
 * and `NMALayoutPositionBottomRight`.
 */
@property (nonatomic) NMALayoutPosition copyrightLogoPosition;

/**
 * The distance in points that the copyright logo will be from the top or
 *  bottom edge of the `NMAMapView`.
 *
 * @note Values less than 10.0 will be ignored.
 */
@property (nonatomic) float copyrightLogoVerticalMargin;

/**
 * The distance in points that the copyright logo will be from the left or
 * right edge of the `NMAMapView`.
 *
 * @note Values less than 10.0 will be ignored.
 *
 * @note Does not apply when the `copyrightLogoPosition` is `NMALayoutPositionTopCenter`
 * or `NMALayoutPositionBottomCenter`.
 */
@property (nonatomic) float copyrightLogoHorizontalMargin;

#pragma mark Animation

/**
 * The point at which map movements and animations are centered.
 *
 * The transformCenter is a point within the bounds of the map that is
 * used to orient the map during transformations. For example, when one
 * of the `-[NMAMapView setGeoCenter:zoomLevel:withAnimation:]` and
 * `-[NMAMapView setGeoCenter:withAnimation:]` methods is used, the specified geocoordinates will
 * be aligned with the transformCenter on the screen.
 *
 * The transformCenter is specified in relative coordinates in the range
 * {[0, 1], [0, 1]}, with {0, 0} representing the upper left corner of the
 * map and {1, 1} the lower right corner.
 *
 * @note The default value is {0.5, 0.5}.
 *
 * @note The center point of map movements caused by gestures will depend
 * on the touch locations of the gestures and not on the transformCenter.
 *
 * @note Values on or very near the edge of the map will be ignored.
 *
 * @note Values above the horizon will be ignored.
 */
@property (nonatomic) CGPoint transformCenter;

/**
 * Sets the geoCenter of the map with optional animation.
 *
 * @param geoCenter The NMAGeoCoordinates at which the map is centered.
 * @param animationType The animation method used to display the transformation.
 */
- (void)setGeoCenter:(NMAGeoCoordinates *)geoCenter
       withAnimation:(NMAMapAnimation)animationType
NS_SWIFT_NAME(set(geoCenter:animation:));

/**
 * Sets the zoomLevel of the map with optional animation.
 *
 * @param zoomLevel The zoomLevel at which to set the map.
 * @param animationType The animation method used to display the transformation.
 */
- (void)setZoomLevel:(float)zoomLevel
       withAnimation:(NMAMapAnimation)animationType
NS_SWIFT_NAME(set(zoomLevel:animation:));

/**
 * Simultaneously sets one or more map transformation properties with optional
 * animation.
 *
 * Any combination of new properties may be passed to this method. To leave a property
 * unchanged, pass nil (geoCenter) or `NMAMapViewPreserveValue` (zoomLevel) for that property.
 *
 * @param geoCenter The new geoCenter.
 * @param zoomLevel The new zoomLevel.
 * @param animationType The animation method used to display the transformation.
 */
- (void)setGeoCenter:(NMAGeoCoordinates *)geoCenter
           zoomLevel:(float)zoomLevel
       withAnimation:(NMAMapAnimation)animationType
NS_SWIFT_NAME(set(geoCenter:zoomLevel:animation:));

/**
 * Positions the `NMAMapView` so that the specified world location coincides
 * with the specified screen location.
 *
 * @note The screen point must be within the bounds of the map view.
 *
 * @note Due to the curvature of the Earth, positioning may be inaccurate at
 * low zoom levels.
 *
 * @note This method ignores map's `padding` and will always navigate to the
 * specified screen point.
 *
 * @param coordinates The world location
 * @param point The screen location
 * @param animation The `NMAMapAnimation` type to use while moving the map
 */
- (void)setGeoCoordinates:(NMAGeoCoordinates *)coordinates
                  toPoint:(CGPoint)point
            withAnimation:(NMAMapAnimation)animation
NS_SWIFT_NAME(set(coordinates:to:animation:));

/**
 * Positions the `NMAMapView` so that the specified world location coincides
 * with the specified screen location.
 *
 * @note The screen point must be within the bounds of the map view.
 *
 * @note Due to the curvature of the Earth, positioning may be inaccurate at
 * low zoom levels.
 *
 * @param coordinates The world location
 * @param point The screen location
 * @param animation The `NMAMapAnimation` type to use while moving the map
 * @param zoomLevel Desired zoom level of the newly-centered `NMAMapView` (pass
 *              `NMAMapViewPreserveValue` to keep the current zoom level)
 */
- (void)setGeoCoordinates:(NMAGeoCoordinates *)coordinates
                  toPoint:(CGPoint)point
            withAnimation:(NMAMapAnimation)animation
                zoomLevel:(float) zoomLevel
NS_SWIFT_NAME(set(coordinates:to:animation:zoomLevel:));

/**
 * Sets the geo bounding box of the map view with optional animation.
 *
 * After this method completes, the full extents of the specified geo bounding
 * box will be visible in the map view. Depending on map orientation, this means
 * that the boundingBox property may return a different value than the one passed
 * to this method, because the map may be displaying some areas outside of the
 * input bounding box.
 *
 * @param boundingBox A `NMAGeoBoundingBox` to display after the transformation
 * @param animationType A `NMAMapAnimation` to illustrate the transformation
 */
- (void)setBoundingBox:(NMAGeoBoundingBox *)boundingBox
         withAnimation:(NMAMapAnimation)animationType
NS_SWIFT_NAME(set(boundingBox:animation:));

/**
 * Transforms the map to fit an arbitrary geo bounding box with the bounds
 * of a specific screen region with optional animation.
 *
 * Passing the bounds of the map view to this method is equivalent to calling
 * `-setBoundingBox:withAnimation:`.
 *
 * @param boundingBox A `NMAGeoBoundingBox` to display after the transformation
 * @param screenRect The region of the view inside which the bounding box will be
 located.
 * @param animationType The animation method used to perform the transformation.
 */
- (void)setBoundingBox:(NMAGeoBoundingBox *)boundingBox
            insideRect:(CGRect)screenRect
         withAnimation:(NMAMapAnimation)animationType
NS_SWIFT_NAME(set(boundingBox:inside:animation:));

#pragma mark Screen / World Conversion

/**
 * Converts a specified on-screen point to an equivalent `NMAGeoCoordinates`
 * object.
 *
 * @param point A point on the screen to convert
 * @return The `NMAGeoCoordinates`, or nil if the conversaion failed
 */
- (nullable NMAGeoCoordinates *)geoCoordinatesFromPoint:(CGPoint)point
NS_SWIFT_NAME(geoCoordinates(from:));

/**
 * Converts a specified `NMAGeoCoordinates` object to its equivalent
 * point in screen space.
 *
 * Valid geo coordinates will produce a valid point, even if the coordinates are
 * not on the screen, as long as the coordinates are not too far from the current map location.
 * To check if coordinates are within the bounds of the screen, use the `CGRectContainsPoint`
 * method after making the conversion.
 *
 * @param coordinates A `NMAGeoCoordinates` object to convert
 * @return The on-screen `CGPoint`, or CGPoint.x = CGPoint.y = -CGFLOAT_MAX
 *         if the `NMAGeoCoordinates` object is nil
 */
- (CGPoint)pointFromGeoCoordinates:(NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(point(from:));

/**
 * Calculates the point distance between two geo coordinates.
 *
 * @note The calculation will fail if the coordinates are too far apart or too
 * far from the current location of the map.
 *
 * @param startCoordinates Starting `NMAGeoCoordinates`
 * @param endCoordinates Ending `NMAGeoCoordinates`
 * @return The point distance between the `NMAGeoCoordinates`, or -CGFLOAT_MAX if
 * either of the coordinates parameters is nil or the calculation cannot be performed.
 */
- (double)pointDistanceFromGeoCoordinates:(NMAGeoCoordinates *)startCoordinates
                         toGeoCoordinates:(NMAGeoCoordinates *)endCoordinates
NS_SWIFT_NAME(pointDistance(from:to:));

#pragma mark - Map Objects

/**
 * Adds a `NMAMapObject` to the `NMAMapView`.
 *
 * @param object A `NMAMapObject` to add
 * @return YES if the map object was added successfully, NO otherwise
 *
 * @note Returns NO if the object has already been added (duplicates are not allowed).
 */
- (BOOL)addMapObject:(NMAMapObject *)object
NS_SWIFT_NAME(add(_:));

/**
 * Adds a `NSArray` of `NMAMapObject` objects to the `NMAMapView`.
 *
 * @param objects A `NSArray` of `NMAMapObject` objects to add
 * @return YES if all map objects were added successfully, NO otherwise
 */
- (BOOL)addMapObjects:(NSArray<__kindof NMAMapObject *> *)objects
NS_SWIFT_NAME(add(objects:));

/**
 * Removes an existing `NMAMapObject` from the `NMAMapView`.
 *
 * @param object A `NMAMapObject` to remove
 * @return YES if the map object was removed successfully, NO otherwise
 */
- (BOOL)removeMapObject:(NMAMapObject *)object
NS_SWIFT_NAME(remove(_:));

/**
 * Removes a `NSArray` of `NMAMapObject` objects from the `NMAMapView`.
 *
 * @param objects A `NSArray` of `NMAMapObject` objects to remove
 * @return YES if all map objects were removed successfully, NO otherwise
 */
- (BOOL)removeMapObjects:(NSArray<__kindof NMAMapObject *> *)objects
NS_SWIFT_NAME(remove(objects:));

/**
 * Returns a `NSArray` of all `NMAMapObject` objects that are selected at
 * a specified point on the screen.
 *
 * @param point An on-screen `CGPoint` specified in logical coordinates
 * @return The `NSArray` of selected `NMAMapObject` objects
 *
 * @note Use `isKindOfClass:` to further determine `NMAMapObject` type instead of
 * `isMemberOfClass:`.
 */
- (NSArray<__kindof NMAMapObject *> *)objectsAtPoint:(CGPoint)point
NS_SWIFT_NAME(objects(at:));

/**
 * Returns a `NSArray` of all visible `NMAMapObject` objects that are
 * selected at a specified point on the screen.
 *
 * @param point An on-screen `CGPoint` specified in logical coordinates
 * @return The `NSArray` of selected `NMAMapObject` objects
 */
- (NSArray<__kindof NMAMapObject *> *)visibleObjectsAtPoint:(CGPoint)point
NS_SWIFT_NAME(visibleObjects(at:));

#pragma mark - Raster Tiles

/**
 * Adds a `NMAMapTileLayer` to the map view for rendering custom raster tiles.
 *
 * @param tileLayer `NMAMapTileLayer` instance to be added to the map view. Ignores
 *                  attempts to add the same `NMAMapTileLayer` instance twice.
 *
 * @note Attempting to add a single `NMAMapTileLayer` instance to multiple NMAMapView
 * instances is not supported and will result in undefined behavior.
 */
- (void)addMapTileLayer:(NMAMapTileLayer *)tileLayer
NS_SWIFT_NAME(add(mapTileLayer:));

/**
 * Removes a `NMAMapTileLayer` from the map view.
 *
 * @param tileLayer `NMAMapTileLayer` instance to be removed from the map view. Does nothing
 *                  if tileLayer has not been added to the map view yet.
 */
- (void)removeMapTileLayer:(NMAMapTileLayer *)tileLayer
NS_SWIFT_NAME(remove(mapTileLayer:));

/**
 * Returns an array of `NMAMapTileLayer` instances that have been added to the
 * map view.
 *
 * @return `NSArray` of `NMAMapTileLayer` instances.
 */
- (NSArray<NMAMapTileLayer *> *)mapTileLayers;

#pragma mark - Language

/**
 * Set the map display language using the device preferred language.
 *
 * @return True if the language is accepted by the map, false otherwise.
 *
 * @note If it fails, the map display language is set to English.
 */
- (BOOL)useDefaultDisplayLanguage;

/**
 * Set the map display language using the locale specifed.
 *
 * @param locale
 *        The `NSLocale` as described in https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSLocale_Class
 * @return True if the locale is accepted by the map, false otherwise.
 */
- (BOOL)useDisplayLanguageFromLocale:(NSLocale *)locale;

/**
 * The language which the map is set to render.
 */
@property (nonatomic, readonly) NSString *displayLanguage;

/**
 * Set the secondary map display language using the locale specifed.
 *
 * Setting a secondary display language will cause the language to be displayed below the
 * primary language for some map labels (e.g. countries).
 *
 * @param locale
 *         Pass nil if you want to remove the secondary map display language.
 *         The NSLocale as described in https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSLocale_Class
 * @return True if the locale is accepted by the map, false otherwise.
 */
- (BOOL)useSecondaryDisplayLanguageFromLocale:(NSLocale * _Nullable)locale;

/**
 * The secondary language which the map is set to render.
 */
@property (nullable, nonatomic, readonly) NSString *secondaryDisplayLanguage;

@end

NS_ASSUME_NONNULL_END

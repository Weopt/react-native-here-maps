/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAAddress;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMAGeocodeRequest;
@class NMAReverseGeocodeRequest;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a factory used to instantiate geocoder requests.
 *
 * A `NMAGeocoder` enables searching for location data by way of the following
 * search services:
 *
 * - One box Geocode - matches a free text query (and location context) to
 * its correct `NMAPlaceLocation` on the map (its latitude and longitude).
 *
 * - Reverse Geocode - retrieves a `NMAPlaceLocation`
 * based on a given `NMAGeoCoordinates`.
 *
 * @note NMAGeocoder requires valid authentication credentials to be set via
 * `NMAApplicationContext`. If valid credentials are not present an attempt to
 * call sharedNMAGeocoder will result in a runtime assert.
 */
@interface NMAGeocoder : NSObject

/**
 * Returns the `NMAGeocoder` singleton instance.
 *
 * @note Use this method to obtain a `NMAGeocoder` instance. Do not call
 * init directly.
 *
 * @return shared `NMAGeocoder` instance
 */
+ (NMAGeocoder *)sharedGeocoder;

/**
 * Creates a geocoder request that resolves a free text query
 * into an array of NMAPlaceLocation.
 * After creating the request, [request startWithListener:(id<NMAResultListener>)] needs
 * to be called to start the search.
 *
 * @param query Query text specifying the search item to locate
 * @param searchArea `NMAGeoBoundingBox` representing the search area
 *                   (this is an optional parameter and should not be set
 *                   unless such functionality is explicitly intended in
 *                   the application)
 * @param geoCoordinates `NMAGeoCoordinates` object representing the location
 *                 context used to search for results that are
 *                 appropriate to the query parameter
 * @return The `NMAGeocodeRequest`
 */
- (NMAGeocodeRequest *)createGeocodeRequestWithQuery:(NSString *)query
                                          searchArea:(nullable NMAGeoBoundingBox *)searchArea
                                     locationContext:(NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_NAME(makeGeocodeRequest(query:searchArea:locationContext:));

/**
 * Creates a geocoder request that resolves a free text query
 * into an array of `NMAPlaceLocation`.
 * After creating the request, `[request startWithListener:(id<NMAResultListener>)]` needs
 * to be called to start the search.
 *
 * @param query Query text specifying the search item to locate
 * @param searchRadius Radius in meters, in which the search should be performed
 * @param geoCoordinates `NMAGeoCoordinates` object representing the location
 *                 context used to search for results that are
 *                 appropriate to the query parameter.  Note that this search
 *                 location can be overridden if the query text already specifies a
 *                 search area, such as a state.
 *
 * @return The NMAGeocodeRequest
 */
- (NMAGeocodeRequest *)createGeocodeRequestWithQuery:(NSString *)query
                                        searchRadius:(NSInteger)searchRadius
                                        searchCenter:(NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_NAME(makeGeocodeRequest(query:searchRadius:searchCenter:));

/**
 * Creates a reverse geocoder request that resolves a
 * NMAGeoCoordinates context into a NMAPlaceLocation.
 * After creating the request, `[request startWithListener:(id<NMAResultListener>)]` needs
 * to be called to start the search.
 *
 * @param geoCoordinates A query `NMAGeoCoordinates` context
 * @return The NMAReverseGeocodeRequest
 */
- (NMAReverseGeocodeRequest *)createReverseGeocodeRequestWithGeoCoordinates:(NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_NAME(makeReverseGeocodeRequest(geoCoordinates:));

@end

NS_ASSUME_NONNULL_END

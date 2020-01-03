/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMADiscoveryRequest;
@class NMALink;

/**
 * Represents the paginated result of a `NMADiscoveryRequest` request.
 *
 * `NMADiscoveryRequest` objects are typically created using the `NMAPlaces` interface to
 * initialize search, explore or here requests.
 *
 * Results may be split into multiple page. Each results page contains a collection of
 * `NMAPlaceLink` and `NMADiscoveryLink` objects, each of which represents either an actual
 * place or a further discovery request.
 *
 */
@interface NMADiscoveryPage : NSObject

/**
 * The total number of available `NMAPlaceLink` or `NMADiscoveryLink` objects for
 * this discovery page.
 */
@property (nonatomic, readonly) NSInteger available;

/**
 * Result offset of the current results page into the total number of results avilable.
 *
 * @note The number of results on the current page is the number of elements in `discoveryResults`.
 */
@property (nonatomic, readonly) NSInteger offsetCount;

/**
 * The `NMADiscoveryRequest` for requesting the next page of results.
 *
 * @note This will be nil if there is no next page.
 */
@property (nullable, nonatomic, readonly) NMADiscoveryRequest *nextPageRequest;

/**
 * Array of `NMAPlaceLink` or `NMADiscoveryLink` objects for the current page of results.
 *
 * @note The discoveryResults may contain more results than the maximum number
 * specified in `NMARequest::collectionSize`. These extra results
 * link to different resources and contain further links via which the user will
 * be linked to a place.
 */
@property (nonnull, nonatomic, readonly) NSArray<__kindof NMALink *> *discoveryResults;

@end

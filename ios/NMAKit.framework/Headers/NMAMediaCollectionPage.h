/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMedia.h"

@class NMAMediaCollectionPageRequest;

/**
 * Represents a paginated collection of `NMAMedia` objects of a specific type.
 *
 * @note Each collection contains objects of a single `NMAMediaType`
 *
 * See also `NMAMedia`
 * See also `NMAMediaCollectionPageRequest`
 */
@interface NMAMediaCollectionPage : NSObject

/**
 * The specialized content type of the objects on the page.
 */
@property (nonatomic, readonly) NMAMediaType type;

/**
 * The total number of available `NMAMedia` objects in this given media collection.
 */
@property (nonatomic, readonly) NSInteger available;

/**
 * The offset count for the current page of the completed `NMAMediaCollectionPageRequest`.
 */
@property (nonatomic, readonly) NSInteger offsetCount;

/**
 * The `NMAMediaCollectionPageRequest` for requesting the next page of the `NMAMediaCollectionPage`.
 *
 * @note This will be nil if no more pages are available.
 */
@property (nullable, nonatomic, readonly) NMAMediaCollectionPageRequest *nextPageRequest;

/**
 * Array of `NMAMedia` objects for the current page
 */
@property (nonnull, nonatomic, readonly) NSArray<__kindof NMAMedia *> *mediaContents;

@end

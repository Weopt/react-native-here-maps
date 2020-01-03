/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALink.h"

@class NMADiscoveryRequest;

/**
 * Represents a discovery search results link that can be used to perform another discovery search.
 */
@interface NMADiscoveryLink : NMALink

/**
 * An NMADiscoveryRequest object to perform another NMADiscoveryPage request.
 */
@property(nonnull, nonatomic, readonly) NMADiscoveryRequest *request;

@end

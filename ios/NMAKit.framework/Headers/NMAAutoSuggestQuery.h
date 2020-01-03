/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAAutoSuggest.h"
#import "NMAAutoSuggestionRequest.h"


/**
 * Represents a suggested query. Query can be used to trigger next
 * Suggest request.
 *
 * See also `NMAAutoSuggestQuery`
 */
@interface NMAAutoSuggestQuery : NMAAutoSuggest

/**
 * The suggested query completion of the given string
 */
@property (nonnull, nonatomic, readonly, strong) NSString *completion;

/**
 * Gets the `NMAAutoSuggestionRequest` to perform the next AutoSuggestion request with
 * the user's chosen completed query term
 */
- (nullable NMAAutoSuggestionRequest *)autoSuggestionRequest;

@end

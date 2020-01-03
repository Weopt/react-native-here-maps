/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents available NMAAutoSuggest derived objects.
 */
typedef NS_ENUM(NSUInteger, NMAAutoSuggestType) {
    /** NMAAutoSuggest object unknown */
    NMAAutoSuggestTypeUnknown = 0,
    /** A link to a suggested place. */
    NMAAutoSuggestTypePlace,
    /** A link to a suggested search. */
    NMAAutoSuggestTypeSearch,
    /** A link to a suggested query. */
    NMAAutoSuggestTypeQuery
};

/**
 * Represents the base interface for suggested places, searches and query.
 *
 * The following specialized type might be available:
 *
 * - place
 *
 * - search
 *
 * - query
 */
@interface NMAAutoSuggest : NSObject

/**
 * The `NSString` representation of the title for this place to be displayed to the user.
 */
@property (nonnull, nonatomic, readonly, strong) NSString *title;

/**
 * The `NSString` representation of the title for this place to be displayed to the user. It contains
 * markup highlighting the parts of the string that were matched.
 *
 * For example: User performs an AutoSuggest search of "Rest" will return the following.
 * title:Joey Restaurant
 * highlightedTitle:Joey <b>Rest</b>aurant
 */
@property (nonnull, nonatomic, readonly, strong) NSString *highlightedTitle;

/**
 * The specialized AutoSuggest type.
 */
@property (nonatomic, readonly) NMAAutoSuggestType type;

@end

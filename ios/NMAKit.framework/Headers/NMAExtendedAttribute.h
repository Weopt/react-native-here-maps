/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents additional detailed information about a `NMAPlace`, an extensible
 * collection of attributes that can include:
 *
 * - Payment - a list of available payment methods (such as cash, credit card, or
 * direct debit, etc)
 *
 * - OpeningHours - a list of hours during which the place is open for business
 *
 * - AnnualClosings - a description of annual closing dates such as holidays or
 * other special occasions
 *
 * - Price - a price list
 *
 * - NearestLandmark - a description of the nearest landmark
 *
 * - LanguagesSpoken - a list of the languages that are spoken at the place
 *
 * - AvailableParking - a list of parking options available nearby
 *
 * - Smoking - a notification of whether smoking is allowed
 *
 * - DisabledAccess - a notification of whether disabled access is available
 */
@interface NMAExtendedAttribute : NSObject

/**
 * Gets the unique identifier for the `NMAExtendedAttribute`.
 * @note See the list of attributes in the class description.
 */
@property (nullable, nonatomic, readonly) NSString *uniqueId;

/**
 * The localized display label for the extended attribute, e.g. "Payment",
 * which can be displayed directly by the client application.
 */
@property (nullable, nonatomic, readonly) NSString *label;

/**
 * The localized text for the extended attribute as NSString, e.g. "VISA",
 * which can be can be displayed directly by the client application.
 *
 * If the text represents a list of items, the items are separated by a
 * line break entity (&lt;br/> if the text format is HTML-encoded
 * or newline if the text format is plain).
 */
@property (nullable, nonatomic, readonly) NSString *text;

@end

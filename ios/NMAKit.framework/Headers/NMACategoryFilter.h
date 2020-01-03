/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

// Common Category String
// defined http://developer.here.com/places#_48_INSTANCE_1FN2Ea4jadS4_=http%3A%2F%2Fdeveloper.here.com%2Fdocs%2Fplaces%2Findex.html%3F

NS_ASSUME_NONNULL_BEGIN

/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_ACCOMODATION;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_ADMINISTRATIVE_AREAS_BUILDINGS;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_EAT_DRINK;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_GOING_OUT;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_LEISURE_OUTDOOR;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_NATURAL_GEOGRAPHICAL;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_SHOPPING;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_SIGHTS_MUSEUMS;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_TRANSPORT;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_PETROL_STATION;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_ATM_BANK_EXCHANGE;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_TOILET_REST_AREA;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_HOSPITAL_HEALTH_CARE_FACILITY;
/// ::nodoc::
FOUNDATION_EXPORT NSString* const CATEGORY_NONE;

NS_ASSUME_NONNULL_END

/**
 * Defines types of categories filter.
 */
typedef NS_ENUM(NSUInteger, NMACategoryFilterType) {
    /** No category. */
    NMACategoryFilterTypeNone = 0,
    /** The accommodation category.*/
    NMACategoryFilterTypeAccommodation,
    /** The administrative-areas-buildings category. */
    NMACategoryFilterTypeAdministrativeAreasBuildings,
    /** The eat-drink category. */
    NMACategoryFilterTypeEatDrink,
    /** The going-out category. */
    NMACategoryFilterTypeGoingOut,
    /** The leisure-outdoor category. */
    NMACategoryFilterTypeLeisureOutdoor,
    /** The natural-geographical category. */
    NMACategoryFilterTypeNaturalGeographical,
    /** The shopping category. */
    NMACategoryFilterTypeShopping,
    /** The sights-museums category. */
    NMACategoryFilterTypeSightsMuseums,
    /** The transport category. */
    NMACategoryFilterTypeTransport,
    /** The petrol-station category. */
    NMACategoryFilterTypePetrolStation,
    /** The atm-bank-exchange category. */
    NMACategoryFilterTypeAtmBankExchange,
    /** The toilet-rest-area category. */
    NMACategoryFilterTypeToiletRestArea,
    /** The hospital-health-care-facility category. */
    NMACategoryFilterTypeHospitalHealthCareFacility
};


/**
 * Represents a filter used when performing a search for popular places within
 * a specific location (exploring). The filter limits a search to specified categories.
 */
@interface NMACategoryFilter : NSObject

/**
 * Adds a `NMACategoryFilterType` to the `NMACategoryFilter`.
 *
 * @param type An `NMACategoryFilterType` filter
 */
- (void)addCategoryFilterFromType:(NMACategoryFilterType)type
NS_SWIFT_NAME(add(fromType:));

/**
 * Adds an `NMACategory`'s uniqueId to the `NMACategoryFilter`.
 *
 * @param uniqueId An `NSString` for `NMACategory`'s uniqueId
 */
- (void)addCategoryFilterFromUniqueId:(nonnull NSString *)uniqueId
NS_SWIFT_NAME(add(fromUniqueId:));

/**
 * Returns a stringified `NMACategoryFilter`, within which individual
 * categories are separated by commas.
 *
 * @return The stringified, comma-delimited set of categories.
 */
- (nonnull NSString *)toString;

@end


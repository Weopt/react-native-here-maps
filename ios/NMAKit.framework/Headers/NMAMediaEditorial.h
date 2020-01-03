/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMedia.h"

/**
 * Represents editorial content about a `NMAPlace`.
 *
 * See also `NMAMediaImage`
 * See also `NMAMediaReview`
 * See also `NMAMediaRating`
 */
@interface NMAMediaEditorial : NMAMedia

/**
 * The `NSString` for this editorial content.
 */
@property (nonnull, nonatomic, readonly) NSString *description;

/**
 * The BCP-47 language code for the editorial text.
 *
 * @note A language code for an editorial is optional and so attempts to read
 * this property could return empty string. In this scenario the language of
 * editorial is unknown but it is likely to be English.
 */
@property (nonnull, nonatomic, readonly) NSString *languageCode;

@end

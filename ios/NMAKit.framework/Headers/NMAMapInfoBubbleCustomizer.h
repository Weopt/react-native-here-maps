/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapInfoBubbleCustomizationContext.h"

/**
 * Responsible for all the customization possible for the map info bubbles.
 */
@interface NMAMapInfoBubbleCustomizer : NSObject

/**
 * Customizes all the map info bubbles with the specified context.
 *
 * @param context The customization context. When it is nil, reverts
 *                back to the default map info bubbles.
 */
+ (void)customize:(nullable NMAMapInfoBubbleCustomizationContext *)context;

@end

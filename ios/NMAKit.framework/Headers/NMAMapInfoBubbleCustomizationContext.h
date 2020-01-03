/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

/**
 * Responsible for all the customizable values for an info bubble.
 */
@interface NMAMapInfoBubbleCustomizationContext : NSObject

#pragma mark - Title

/**
 * The default title label uses 12.0 bold system font, has black text and clear
 * background colors and its text alignment is justified. All the other settings keeps
 * the UILabel default values.
 */
@property (nonnull, nonatomic, strong) UILabel *titleLabel;

#pragma mark - Description

/**
 * The default description title label uses 11.0 system font, has black text and clear
 * background colors and its text alignment is justified. All the other settings keeps
 * the `UILabel` default values.
 */
@property (nonnull, nonatomic, strong) UILabel *descriptionLabel;

#pragma mark - Bubble

/**
 * The maximum width of the info bubble. If the text don't fit into this width,
 * the text will be multiline.
 * The default value is 150.0.
 */
@property (nonatomic) CGFloat bubbleMaxWidth;

/**
 * The alpha of the info bubble.
 * The default value is 1.0.
 */
@property (nonatomic) CGFloat bubbleAlpha;

/**
 * The radius to use when drawing the corners. For rounded corners use a nonzero value.
 * The default value is 0.0, i.e no rounded corners.
 */
@property (nonatomic) CGFloat bubbleCornerRadius;

/**
 * Outside margin for the whole bubble shape. When the info bubble is on the map view
 * there should be left and right margin at least equal to this value. If not, the text
 * will be multiline.
 * The default value is 25.0.
 */
@property (nonatomic) CGFloat bubbleLeftRightMargin;

/**
 * Left, top, right and bottom margin for the text area, i.e. title & description.
 * The default value is 4.0.
 */
@property (nonatomic) CGFloat bubblePadding;

/**
 * The default value is 8.0.
 */
@property (nonatomic) CGFloat bubbleTailWidth;

/**
 * The default value is 8.0.
 */
@property (nonatomic) CGFloat bubbleTailHeight;

/**
 * The width of the border line.
 * The default value is 1.0.
 */
@property (nonatomic) CGFloat bubbleLineWidth;

/**
 * The color of the border line.
 * The default value is black.
 */
@property (nonnull, nonatomic, strong) UIColor *bubbleStrokeColor;

/**
 * The default value is white.
 */
@property (nonnull, nonatomic, strong) UIColor *bubbleFillColor;

@end

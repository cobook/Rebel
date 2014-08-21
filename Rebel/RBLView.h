//
//  RBLView.h
//  Rebel
//
//  Created by Justin Spahr-Summers on 2012-07-29.
//  Copyright (c) 2012 GitHub. All rights reserved.
//

#import <Cocoa/Cocoa.h>

// A base class for saner, more full-featured layer-backed views with support
// for MVVM.
@interface RBLView : NSView

// A background color for the view, or nil if none has been set. This property
// is not the same as CALayer.backgroundColor, but does manipulate it.
@property (nonatomic, strong) NSColor *backgroundColor;

// Whether the view's content and subviews clip to its bounds. This property
// is not the same as CALayer.masksToBounds, but does manipulate it.
//
// Defaults to NO.
@property (nonatomic, assign) BOOL clipsToBounds;

// A radius used to draw rounded corners for the view's background. This property
// is not the same as CALayer.cornerRadius, but does manipulate it.
//
// Typically, you will want to enable clipsToBounds when setting this property
// to a non-zero value.
//
// Defaults to 0.
@property (nonatomic, assign) CGFloat cornerRadius;

// Whether the graphics context for the view's drawing should be cleared to
// transparent black in RBLView's implementation of -drawRect:.
//
// Defaults to YES.
@property (nonatomic, assign) BOOL clearsContextBeforeDrawing;

// A prerendered image to use as the content for this view. This property is
// not the same as CALayer.contents, but does manipulate it.
//
// The behavior of this property is undefined if -drawRect: is overridden.
@property (nonatomic, strong) NSImage *contents;

// Subclasses may override this method to redraw the given rectangle. Any
// override of this method should invoke super.
- (void)drawRect:(NSRect)rect;

@property (readwrite, getter=isFlipped) BOOL flipped;
@property (readwrite, getter=isOpaque) BOOL opaque;
@property NSViewLayerContentsRedrawPolicy layerContentsRedrawPolicy;

@end

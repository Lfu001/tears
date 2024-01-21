//
//  ViewController.mm
//
//
//  Created by Lfu001 on 2024/01/20.
//  Copyright © 2024 tears team. All rights reserved.
//

#import <MetalANGLE/GLES2/gl2.h>
#import <MetalANGLE/MGLKit.h>
#import "gl/GLController.hpp"
#import "ViewController.h"

using namespace tears;

@interface ViewController ()
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.preferredFramesPerSecond = 60;

    MGLContext* context = [[MGLContext alloc] initWithAPI:kMGLRenderingAPIOpenGLES2];
    self.glView.context = context;
    [MGLContext setCurrentContext:context];

    CGSize size = [self getSize];
    GLController::getInstance()->setViewSize(size.width, size.height);
}

- (void)mglkView:(MGLKView*)view drawInRect:(CGRect)rect {
    GLController::getInstance()->draw();
}

- (CGSize)getSize {
    return self.glView.drawableSize;
}

@end

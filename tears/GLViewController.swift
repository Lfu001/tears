//
//  GLViewController.swift
//  tears
//
//  Created by Lfu001 on 2024/01/27.
//  Copyright © 2024 tears team. All rights reserved.
//

import UIKit

class GLViewController: MGLKViewController {
    var tearsEngine: tears.TearsEngine? = nil

    override func viewDidLoad() {
        super.viewDidLoad()

        self.preferredFramesPerSecond = 60

        let glContext = MGLContext(api: kMGLRenderingAPIOpenGLES2)
        self.glView?.context = glContext
        MGLContext.setCurrent(glContext)

        tearsEngine = tears.TearsEngine()
        let size = getSize()
        tearsEngine?.setViewSize(Int32(size.width), Int32(size.height))
    }

    override func mglkView(_ view: MGLKView!, drawIn rect: CGRect) {
        tearsEngine?.runOneLoop()
    }

    func getSize() -> CGSize {
        return self.glView?.drawableSize ?? CGSize(width: 0.0, height: 0.0)
    }

}

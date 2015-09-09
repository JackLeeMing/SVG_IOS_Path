//
//  ViewController.swift
//  SVG_Pro
//
//  Created by 李嘉魁 on 15/9/9.
//  Copyright (c) 2015年 李嘉魁. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    let myShapeLayer = CAShapeLayer()
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //1: Turn your SVG into a CGPath:
        let myPath = SVGParser.pathFromSVGFileNamed("BezierCurve1").takeUnretainedValue()
        
        
        //2: To display it on screen, you can create a CAShapeLayer
        //and set myPath as its path property:
        
        myShapeLayer.path = myPath
        
        
        //3: Fiddle with it using CAShapeLayer's properties:
        myShapeLayer.strokeColor =  UIColor(red: 1, green: 1, blue: 1, alpha: 1.0).CGColor
        myShapeLayer.lineWidth = 3
        myShapeLayer.fillColor = UIColor.clearColor().CGColor
        
        
        //4: Display it!
        self.view.layer.addSublayer(myShapeLayer)
        
        
        
        
        
        //Make it smaller if we're on an iPhone:
        if UIDevice.currentDevice().userInterfaceIdiom == .Phone {
            myShapeLayer.transform = CATransform3DMakeScale(0.5, 0.5, 0.5)
        }
        
        self.view.backgroundColor = UIColor(red: 0.0324, green: 0.0079, blue: 0.0399, alpha: 1.0)
    }
    
    override func viewDidAppear(animated: Bool) {
        let animateStrokeEnd = CABasicAnimation(keyPath: "strokeEnd")
        animateStrokeEnd.duration = 5.5
        animateStrokeEnd.fromValue = 0.0
        animateStrokeEnd.toValue = 1.0
        animateStrokeEnd.removedOnCompletion = true
        // add the animation
        myShapeLayer.addAnimation(animateStrokeEnd, forKey: "animate stroke end animation")
        
        myShapeLayer.fillColor = UIColor(red: 0.1038, green: 0.8085, blue: 0.7274, alpha: 1.0).CGColor
    }
    
}



use SVG you can get different kinds of paths for code or pictures
.svg 文件内容样式，实际保存的是路径点轨迹，是一个xml文件，所以实际的绘制就是解析文件获取点绘制曲线，至于动画效果其实就是给轨迹添加一个简单地动画。
svg 轨迹标识：
- M = moveto   相当于 android Path 里的moveTo(),用于移动起始点
- L = lineto   相当于 android Path 里的lineTo()，用于画线
- H = horizontal lineto     用于画水平线
- V = vertical lineto       用于画竖直线
- C = curveto               相当于cubicTo(),三次贝塞尔曲线
- S = smooth curveto        同样三次贝塞尔曲线，更平滑
- Q = quadratic Belzier curve             quadTo()，二次贝塞尔曲线
- T = smooth quadratic Belzier curveto    同样二次贝塞尔曲线，更平滑
- A = elliptical Arc   相当于arcTo()，用于画弧
- Z = closepath     相当于closeTo(),关闭path
![Demo Image](https://github.com/JackLeeMing/SVG_IOS_Path/blob/master/art/svg.png)









![Demo Image](https://github.com/JackLeeMing/SVG_IOS_Path/blob/master/art/playerd.gif)










![Demo Image](https://github.com/JackLeeMing/SVG_IOS_Path/blob/master/art/ChinaMaps.gif)

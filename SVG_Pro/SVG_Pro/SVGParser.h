

#import "TargetConditionals.h"

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

@interface SVGParser : NSObject {
@private
    float			pathScale;
#if TARGET_OS_IPHONE
    UIBezierPath    *bezier;
#else
    NSBezierPath    *bezier;
#endif
    CGPoint			lastPoint;
    CGPoint			lastControlPoint;
    NSCharacterSet  *separatorSet;
    NSCharacterSet  *commandSet;
    
    NSMutableArray  *tokens;
}

typedef NS_ENUM(NSInteger, PocketSVGControlPoint) {
    PocketSVGControlPointInvalid,
    PocketSVGControlPointS,
    PocketSVGControlPointQ
};

@property(nonatomic) PocketSVGControlPoint controlPointType;
@property(nonatomic,assign)NSUInteger conDext;

#if TARGET_OS_IPHONE
@property(nonatomic, readonly) UIBezierPath *bezier;
#else
@property(nonatomic, readonly) NSBezierPath *bezier;
#endif


/*!
 *  Returns a CGPathRef corresponding to the path represented by a local SVG file's d attribute.
 *
 *  @param nameOfSVG The name of the SVG file. The methods looks for a SVG with the specified in the application's main bundle.
 *
 *  @return A CGPathRef object for the SVG in the specified file, or nil if the object could not be found or could not be parsed.
 */
+ (CGPathRef)pathFromSVGFileNamed:(NSString *)nameOfSVG;

/*!
 *  Returns a CGPathRef corresponding to the path represented by a local SVG file's D attribute
 *
 *  @param svgFileURL The URL to the file.
 *
 *  @return A CGPathRef object for the SVG in the specified file, or nil if the object could not be found or could not be parsed.
 */
+ (CGPathRef)pathFromSVGFileAtURL:(NSURL *)svgFileURL;

/*!
 *  Returns a CGPathRef corresponding to the path represented by a string with SVG formatted contents.
 *
 *  @param svgString The string containing the SVG formatted path.
 *
 *  @return A CGPathRef object for the SVG in the string, or nil if no path is found or the string could not be parsed.
 */
+ (CGPathRef)pathFromSVGString:(NSString *)svgString;

/*!
 *  Returns a CGPathRef corresponding to the path represented by a string with the contents of the d attribute of a path node in an SVG file.
 *
 *  @param dAttribute The string containing the d attribute with the path.
 *
 *  @return A CGPathRef object for the path in the string, or nil if no path is found or the string could not be parsed.
 */
+ (CGPathRef)pathFromDAttribute:(NSString *)dAttribute;


/*!
 *  Returns a PocketSVG object initialized with nameOfSVG
 *
 *  @param nameOfSVG The name of the SVG file.  The methods looks for a SVG with the specified in the application's main bundle.
 *
 *  @return The PocketSVG object for the specified file, or nil if the object could not be found or could not be parsed.
 */
- (instancetype)initFromSVGFileNamed:(NSString *)nameOfSVG __attribute__((deprecated));

/*!
 *  Returns a PocketSVG object initialized with svgFileURL
 *
 *  @param svgFileURL The URL to the file.
 *
 *  @return The PocketSVG object for the specified file, or nil if the object could not be found or could not be parsed.
 */
- (instancetype)initWithURL:(NSURL *)svgFileURL __attribute__((deprecated));



#if !TARGET_OS_IPHONE
+ (CGPathRef)getCGPathFromNSBezierPath:(NSBezierPath *)quartzPath;
#endif

@end


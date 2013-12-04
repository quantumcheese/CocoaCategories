#import <Cocoa/Cocoa.h>

// MARK: Interface

@interface NSDictionary (Enumeration)
- (void)enumerateKeysAndObjectsPassingTest:(BOOL (^)(id key, id obj, BOOL *stop))predicate
                                usingBlock:(void (^)(id key, id obj, BOOL *stop))block;
@end

// MARK: Implementation

@implementation NSDictionary (Enumeration)

- (void)enumerateKeysAndObjectsPassingTest:(BOOL (^)(id key, id obj, BOOL *stop))predicate
                                usingBlock:(void (^)(id key, id obj, BOOL *stop))block
{
    [self enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        if (predicate(key, obj, stop) && !stop) {
            block(key, obj, stop);
        }
    }];
}

@end

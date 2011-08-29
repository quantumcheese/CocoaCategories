@interface NSArrray (Fold)
- (NSArray *)foldSelector:(SEL)aSel;
@end

@implementation NSArray (Fold)

- (NSArray *)foldSelector:(SEL)aSel
{
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[self count]];
	for (id obj in self)
	{
		[array addObject:[obj performSelector:aSel]];
	}
	return [NSArray arrayWithArray:[array autorelease]];
}

@end


@interface NSMutableArray (Map)
- (void)mapSelector:(SEL)aSel;
@end

@implementation NSMutableArray (Map)

- (void)mapSelector:(SEL)aSel
{
	for (NSInteger i = 0, count = [self count]; i != count; ++i)
	{
		id obj = [self objectAtIndex:i];
		id replacement = [obj performSelector:aSel];
		[self replaceObjectAtIndex:i withObject:replacement];
	}
}

@end



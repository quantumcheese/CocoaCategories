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

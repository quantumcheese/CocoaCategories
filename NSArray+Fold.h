// MARK: Interfaces

@interface NSArrray (Fold)
- (NSArray *)foldSelector:(SEL)aSel;
- (NSArray *)foldBlock:(id(^)(id))aBlock;
@end

@interface NSMutableArray (Map)
- (void)mapSelector:(SEL)aSel;
- (void)mapBlock:(id (^)(id))aBlock;
@end

// MARK: --
// MARK: Implementations

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

- (NSArray *)foldBlock:(id(^)(id))aBlock
{
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[self count]];
	for (id obj in self)
	{
		[array addObject:aBlock(obj)];
	}
	return [NSArray arrayWithArray:[array autorelease]];
}
}

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

- (void)mapBlock:(id (^)(id))aBlock
{
	for (NSInteger i = 0, count = [self count]; i != count; ++i)
	{
		id obj = [self objectAtIndex:i];
		id replacement = aBlock(obj);
		[self replaceObjectAtIndex:i withObject:replacement];
	}
}

@end


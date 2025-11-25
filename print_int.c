int print_int(va_list args)
{
	int i = va_arg(args, int), j;

	if (i < 0)
	{
		_putchar('-');
		i = -i;
	}
	if (i >= 10)
	{
		print_int(i / 10);
	}
}

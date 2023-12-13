/**
 * _fill_buff_ - copy source to destination
 * @dest: destination
 * @source: source
 */
void _fill_buff_(char *dest, char *source)
{
	char *temp;

	temp = dest;
	/*copy source to destination*/
	while (*source != '#' && *source)
	{
		*temp = *source;
		source++;
		temp++;
	}
	/*Null terminate the temp*/
	*temp = '\0';
}

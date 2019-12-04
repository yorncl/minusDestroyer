./ft_printf_output.out > output/ft_printf_output
./printf_output.out > output/printf_output

difference=$(diff output/ft_printf_output output/printf_output)
rslt=$(diff output/ft_printf_output output/printf_output | wc -l)
if [[ $rslt -eq "0" ]]; then
 	printf "\033[1;32mYou've got 0 errors\033[0m\n"
elif [[ "$difference" = "Binary files test/output/ft_printf_output and output/printf_output differ" ]]; then
 	printf "\033[1;31mBinary files differs\033[0m\n" $rslt
else
 	printf "\033[1;31mYou've got %d errors\033[0m\n" $rslt
	echo $difference
fi
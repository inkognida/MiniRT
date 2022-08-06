/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:35:06 by hardella          #+#    #+#             */
/*   Updated: 2022/08/06 13:47:35 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}


int main(void) {
	char str[5] = "aboba";

	printf("%s\n", str);	
	printf("%s\n", "ilya iz ozona and artem iz ebanoy pomoiki present");
}


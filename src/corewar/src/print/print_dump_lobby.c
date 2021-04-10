/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump_lobby.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:30:43 by mschimme          #+#    #+#             */
/*   Updated: 2021/04/10 14:57:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	TD	ДОПИСАТЬ вывод результата (и фсё);
TD:	Декларация - заглушка. Подобрать список нужных параметров.
!Контракт:
	*	Просто выводит состояние арены в текущий момент.
	*	Принимает указатель на указатель головы t_vasa, которые в своем 
	* ->gen.cyc_sol хранят циклы, в которые необхоимо дампнуться.
	*	Через голову управляет цепочкой дампов.
	*	Отпработав последний дамп-цикл должна подать сигнал на прерывание работы
	*	цикла (возвратить 1).

! Арена начинается на &arena[sizeof(RTP)]. "Уши" по бокам - буферные, для работы
	! машинными словами при чтении / вставке данных на арену. Эти уши должны
	! быть за рамками функций чтения и записи на арена затерты '\0', потому
	! в выводе полезной нагрузке не имеют.
! do ... while запрещен по норме.


*/
uint8_t	ft_print_dump(t_world *nexus)
{
	t_vasa		*ptr;
	t_vasa		**cycle;
	char 		str[64 * 2 + 64];
	char 		*str_cpy;
	uint8_t		*bytes;

	cycle = &nexus->cyc.cyc_to_dump;
	ptr = *cycle;

	bytes = nexus->arena;
	size_t i = 0;
	size_t max = MEM_SIZE + sizeof(RTP) * 2;
	while (i < max)
	{
		str_cpy = str;
		ft_printf("%.8x:\t", i);
		do
		{
			uint8_t tmp = *bytes / 16;
			*str_cpy++ = tmp +  (tmp > 9 ? 'A' - 10 : '0');
			tmp = *bytes++ % 16;
			*str_cpy++ = tmp + (tmp > 9 ? 'A' - 10 : '0');
			*str_cpy++ = ' ';
			i++;
		} while ((i % 0x40) && i < max);
		str[64 * 2 + 63] = 0;
		ft_putendl(str);
	}
	ft_putendl("");
	*cycle = (*cycle)->next;
	ptr->gen.cyc_sol = 0;
	free(ptr);
	ptr = *cycle;
	return (*cycle == NULL);
}
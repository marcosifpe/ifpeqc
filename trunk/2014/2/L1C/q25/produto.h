/*
 * produto.h
 *
 *  Created on: 01/11/2014
 *      Author: MASC
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

unsigned produto(unsigned a, unsigned b) {
	if (b == 1)
		return a;
	else
		return produto(a, b - 1) + a;
}

#endif /* PRODUTO_H_ */

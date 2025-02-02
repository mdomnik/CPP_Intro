/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:38:16 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/01 22:47:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int replacefile(std::string fileName, std::string str1, std::string str2)
{
	std::ifstream file(fileName.c_str());
	if (!file)
		{
			std::cerr << "Error: file not found" << std::endl;
			return 1;
		}
	std::string outfileName = fileName + ".replace";
	std::ofstream outfile(outfileName.c_str());
	std::string buffer;

	while(getline(file, buffer))
	{
		ssize_t pos = 0;
		pos = buffer.find(str1);
		do
		{
			if (pos >= 0)
			{
				buffer.erase(pos, str1.length());
				buffer.insert(pos, str2);
				pos = buffer.find(str1, pos + str2.length());
			}
			else
				break;
		} while (pos != -1);
		outfile << buffer << std::endl;
		buffer.clear();
	}
	return (0);
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename str1 str2" << std::endl;
		return 1;
	}

	std::string fileName = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];

	if (str1.empty())
	{
		std::cerr << "Error: str1 cannot be an empty string" << std::endl;
		return 1;
	}

	return (replacefile(fileName, str1, str2));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:05:40 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/04 18:37:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Constructors and Copy Assignment Test
	{
		std::cout << "\033[1;35m=== Constructors & Assignment Test ===\033[0m" << std::endl;

		// Default constructor
		try
		{
			Bureaucrat defaultBureaucrat;
			std::cout << "Default constructor: " << defaultBureaucrat << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Default constructor failed: " << e.what() << std::endl;
		}

		// Name and grade constructor
		try
		{
			Bureaucrat initBureaucrat("Eo", 42);
			std::cout << "name/grade constructor: " << initBureaucrat << std::endl;

			// Copy constructor
			Bureaucrat copyBureaucrat(initBureaucrat);
			std::cout << "Copy constructor: " << copyBureaucrat << std::endl;

			// Copy assignment
			Bureaucrat assignedBureaucrat;
			assignedBureaucrat = initBureaucrat;
			std::cout << "Copy assignment: " << assignedBureaucrat << std::endl;

		}
		catch (const std::exception& e)
		{
			std::cerr << "Constructor test failed: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Constructors & Assignment Test Concluded ===\033[0m\n" << std::endl;
	}

	// Getters Test
	{
		std::cout << "\033[1;35m=== Getters Test (getName & getGrade) ===\033[0m" << std::endl;

		try
		{
			Bureaucrat Titus("Titus", 42);
			std::cout << "Created Bureaucrat: " << Titus << std::endl;

			std::cout << "getName(): " << Titus.getName() << std::endl;
			std::cout << "getGrade(): " << Titus.getGrade() << std::endl;

			std::cout << "\nIncrementing grade...\n";
			Titus.incrementGrade();
			std::cout << "Updated grade: " << Titus.getGrade() << std::endl;

			std::cout << "\nDecrementing grade twice...\n";
			Titus.decrementGrade();
			Titus.decrementGrade();
			std::cout << "Updated grade: " << Titus.getGrade() << std::endl;

		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception caught during getters test: " << e.what() << std::endl;
		}

		std::cout << "\033[1;35m=== Getters Test Concluded ===\033[0m\n" << std::endl;
	}

	// Valid Construction Test
	{
		std::cout << "\033[1;35m=== Valid Construction Test ===\033[0m" << std::endl;
		try
		{
			Bureaucrat Maciej("Maciej", 75);
			std::cout << Maciej << std::endl;

			Bureaucrat Ferni("Ferni", 1);
			std::cout << Ferni << std::endl;

			Bureaucrat Archie("Archie", 150);
			std::cout << Archie << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Valid Construction Test Concluded ===\033[0m\n" << std::endl;
	}

	// Invalid Construction Test
	{
		std::cout << "\033[1;35m=== Invalid Construction Test ===\033[0m" << std::endl;
		try
		{
			Bureaucrat tooHigh("HighGrade", 0);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat tooLow("LowGrade", 151);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Invalid Construction Test Concluded ===\033[0m\n" << std::endl;
	}

	// Grade Incrementation Test
	{
		std::cout << "\033[1;35m=== Grade Incrementation Test ===\033[0m" << std::endl;
		try
		{
			Bureaucrat Darrow("Darrow", 2);
			std::cout << Darrow << std::endl;
			Darrow.incrementGrade(); // should go to 1
			std::cout << "After increment: " << Darrow << std::endl;

			Darrow.incrementGrade(); // should throw
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Grade Incrementation Test Concluded ===\033[0m\n" << std::endl;
	}

	// Grade Decrementation Test
	{
		std::cout << "\033[1;35m=== Grade Decrementation Test ===\033[0m" << std::endl;
		try {
			Bureaucrat Sevro("Sevro", 149);
			std::cout << Sevro << std::endl;
			Sevro.decrementGrade(); // should go to 150
			std::cout << "After decrement: " << Sevro << std::endl;

			Sevro.decrementGrade(); // should throw
		} catch (const std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Grade Decrementation Test Concluded ===\033[0m\n" << std::endl;
	}

	// Multiple Bureaucrats Test
	{
		std::cout << "\033[1;35m=== Multiple Bureaucrats Test ===\033[0m" << std::endl;
		try
		{
			Bureaucrat j("Jackal", 50);
			Bureaucrat m("Mustang", 120);
			Bureaucrat p("Pax", 10);

			std::cout << j << std::endl;
			std::cout << m << std::endl;
			std::cout << p << std::endl;

			j.incrementGrade();
			m.decrementGrade();
			p.incrementGrade();

			std::cout << "After changes:\n";
			std::cout << j << std::endl;
			std::cout << m << std::endl;
			std::cout << p << std::endl;

		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << "\033[1;35m=== Multiple Bureaucrats Test Concluded ===\033[0m\n" << std::endl;
	}

	// Stream Output Format Test
	{
		std::cout << "\033[1;35m=== Stream Output Format Test ===\033[0m" << std::endl;
		Bureaucrat Cassius("Cassius", 42);
		std::cout << "Expected format: <name>, bureaucrat grade <grade>\n";
		std::cout << "Actual: " << Cassius << std::endl;
		std::cout << "\033[1;35m=== Stream Output Format Test Concluded ===\033[0m\n" << std::endl;
	}

	{
		std::cout << "\033[1;32m=== Bureaucrat Tests Concluded ===\033[0m" << std::endl;
	}
	return 0;
}

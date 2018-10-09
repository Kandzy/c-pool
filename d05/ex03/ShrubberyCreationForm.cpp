#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("UNDEFINED", "Shrubbery Creation Form", 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "Shrubbery Creation Form", 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf) : Form(scf.getTarget(), "Shrubbery Creation Form", 145, 137)
{
	*this = scf;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &scf)
{
	(void)scf;
	return *this;
}

void					ShrubberyCreationForm::execute(Bureaucrat const &bu) const
{
	if ((this->getSigned()) && (bu.getGrade() <= this->getExeGrade()))
	{
		std::ofstream  file;
		file.open(getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
		if (file.fail())
		{
			std::cerr << "Cannot open file" << std::endl;
		}
		file 	 << "              _{\\ _{\{\\/}/}/}__\n" <<
					"             {/{/\\}{/{/\\}(\\}{/\\} _\n" <<
					"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n" <<
					"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n" <<
					"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n" <<
					"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n" <<
					"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n" <<
					"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n" <<
					"     {/{/{\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n" <<
					"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n" <<
					"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n" <<
					"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n" <<
					"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n" <<
					"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n" <<
					"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n" <<
					"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n" <<
					"             {/{\\{\\{\\/}/}{\\{\\/\\}/}\n" <<
					"              {){/ {\\/}{\\/} \\}\\}\n" <<
					"              (_)  \\.-'.-/\n" <<
					"          __...--- |'-.-'| --...__\n" <<
					"   _...--/=\"   .-' |'-.-'|  ' -.  \"\"--..__\n" <<
					" -\"    ' .  . '    |.'-._| '  . .  '   \"-\n" <<
					" .  '-  '    .--'  | '-.'|    .  '  . '\n" <<
					"          ' ..     |'-_.-|\n" <<
					"  .  '  .       _.-|-._ -|-._  .  '  .\n" <<
					"              .'   |'- .-|   '.\n" <<
					"  ..-'   ' .  '.   `-._.-´   .'  '  - .\n" <<
					"   .-' '        '-._______.-'     '  .\n" <<
					"        .      ~,\n" <<
					"    .       .   |\\   .    ' '-.\n" <<
					"    ___________/  \\____________\n" <<
					"   /  Why is it, when you want  \\ \n" <<
					"  |  something, it is so damn   |\n" <<
					"  |    much work to get it?     |\n" <<
					"   \\___________________________/\n" << std::endl;
	}
	else if (!this->getSigned())
		throw Form::UnsignedExeprion();
	else
		throw Form::GradeTooLowException();
	return;
}

std::ostream			&operator<<(std::ostream &out, ShrubberyCreationForm const &scf)
{
	out << scf.getName()+":" << std::endl
	<< "				Target:" + scf.getTarget() << std::endl
	<< "				Sign grade required: " << scf.getReqGrade() << std::endl
	<< "				Execution grade required: " << scf.getExeGrade() << std::endl
	<< "				Status: " << (scf.getSigned() ? "True" : "False") << std::endl;
	return (out);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}


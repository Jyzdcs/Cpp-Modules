#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP
# include <iostream>
# include <fstream>
# include <string>

class FileHandler {
	private:
		std::string _outputFileName;
		std::string _fileContent;
		std::string	_occurence;
		std::string _replaceStr;
		std::string _outputFileContent;

	public:
		FileHandler(std::string newFileName);

		bool	exportFileContent();

		bool	replaceOccurence();

		void	setOccurence(std::string occurence);
		void	setReplaceStr(std::string path);
		bool	setFileContent(std::string path);

		const	std::string&	getFileContext() const;
		const	std::string&	getOutputFileContent() const;
		const	std::string&	getOccurence() const;
		const	std::string&	getReplaceStr() const;
		const	std::string&	getOutputFileName() const;
};

#endif
#include "FileHandler.hpp"

FileHandler::FileHandler(std::string newFileName) : _outputFileName(newFileName) {};

void	FileHandler::exportFileContent() {
	std::ofstream outfile(_outputFileName.c_str());

	if (!outfile.is_open()) {
		std::cerr << "Error: cannont create file\n";
	}

	outfile << _outputFileContent;

	outfile.close();
};

void	FileHandler::replaceOccurence() {
	size_t subPos = 0;
	size_t pos = 0;

	while ((subPos = _fileContent.find(_occurence, pos)) != std::string::npos)
	{
		_outputFileContent.append(_fileContent, pos, subPos - pos);

		_outputFileContent += _replaceStr;

		pos = subPos + _occurence.length();
	}
	_outputFileContent.append(_fileContent, pos, std::string::npos);
};

bool	FileHandler::setFileContent(std::string path) {
	std::ifstream file(path.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: cannont open file\n";
		return (false);
	}

	std::string line;

	while (std::getline(file, line)) {
		_fileContent += line;
		if (!file.eof())
			_fileContent += '\n';
	}
	
	file.close();
	return (true);
};

void	FileHandler::setOccurence(std::string occurence) {
	_occurence = occurence;
};

void	FileHandler::setReplaceStr(std::string replaceStr) {
	_replaceStr = replaceStr;
};

const std::string& FileHandler::getFileContext() const {
	return _fileContent;
};

const	std::string&	FileHandler::getOutputFileContent() const {
	return _outputFileContent;
};

const	std::string&	FileHandler::getOccurence() const {
	return _occurence;
};

const	std::string&	FileHandler::getReplaceStr() const {
	return _replaceStr;
};

const	std::string&	FileHandler::getOutputFileName() const {
	return _outputFileName;
};


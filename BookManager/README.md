# Entity Management System with Configurable Repositories and Undo/Redo

This project is a configurable entity management system that handles multiple types of data (e.g., cars, clients, rentals) with flexible storage options and advanced undo/redo capabilities. The system can store data in memory, in text files, or in binary files, with the storage method configurable via a properties file. Built with a layered architecture, the system leverages a repository pattern for modularity and ease of extension.

## Features

### 1. Configurable Repository Layer with Multiple Storage Options
The system provides three types of repositories for flexible data storage:
   - **In-Memory Repository**: Stores data temporarily in memory for fast access.
   - **Text File Repository**: Saves data in human-readable text files, allowing for persistent storage in plain text.
   - **Binary File Repository**: Uses Python's `pickle` library for serialized binary file storage, which provides more efficient, compact storage.

### 2. Easy-to-Use Configuration with `settings.properties`
   - The system can be configured using a `settings.properties` file, which specifies:
     - The repository type (in-memory, text file, or binary file)
     - File paths for each data entity (if applicable)
   - By editing the properties file, users can seamlessly switch storage types or file locations without modifying the code.



### 3. Advanced Undo/Redo Functionality
   - **Unlimited Undo/Redo**: The system allows users to undo or redo all operations performed, ensuring no action is irreversible.
   - **Memory-Efficient Implementation**: The **Command design pattern** is used to implement undo/redo functionality, making it lightweight and organized.
   - **Cascading Undo/Redo**: The system ensures that related data operations are handled together, so undoing or redoing an action affects all associated data (e.g., undoing a client deletion also restores their rentals).

## Technical Design

- **Layered Architecture**: The codebase follows a layered architecture that separates repository logic from business logic and the user interface, enhancing maintainability, testability, and code clarity.
- **Repository Inheritance**: File-based repositories inherit from the base in-memory repository and extend it with file-specific logic, promoting code reuse.
- **Binary Serialization with Pickle**: Binary file storage is managed with Python’s `pickle` library, enabling efficient serialization and deserialization of data.

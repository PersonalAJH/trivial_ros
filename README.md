# trivial_ros
example of ros 
developing


workspace_folder/        -- WORKSPACE
start_ros.sh              -- start shell file
  src/                   -- SOURCE SPACE
    CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
    main_node/
      CMakeLists.txt     -- CMakeLists.txt file for package_1
      package.xml        -- Package manifest for package_1
    sub_node/
      CMakeLists.txt     -- CMakeLists.txt file for package_2
      package.xml        -- Package manifest for package_2
    pub_node/
      CMakeLists.txt     -- CMakeLists.txt file for package_n
      package.xml        -- Package manifest for package_n
    jh_msgs/
      CMakeLists.txt     -- CMakeLists.txt file for package_n
      package.xml        -- Package manifest for package_n
      
      
      
      

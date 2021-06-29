{
    "variables": {
        "NIM_SDK_DIR%": "<(PRODUCT_DIR)/../../nim_sdk",
        "SOURCE_DIR": "<(PRODUCT_DIR)/../../"
    },
    "targets": [
        {
            'target_name': 'nim-chatroom',
            'includes': [
            ],
            'include_dirs': [
            ],
            'sources': [
                'src/nim_chatroom_node_engine.cpp',
                'src/nim_chatroom_node_engine.h',
                'src/api/nim_chatroom_node.cpp',
                'src/api/nim_chatroom_node.h',
                'src/api/nim_chatroom_node_event_handler.h',
                'src/api/nim_chatroom_node_event_handler.cpp',
                'src/helper/nim_chatroom_node_helper.h',
                'src/helper/nim_chatroom_node_helper.cpp',
                'src/nim_node_helper.h',
                'src/nim_node_helper.cpp',
                'src/nim_node_async_queue.h',
                'src/nim_node_async_queue.cpp',
                'src/nim_event_handler.h',
                'src/nim_event_handler.cpp',
            ],
            'conditions': [
                [
                    'OS=="win"',
                    {
                        'copies': [{
                            'destination': '<(PRODUCT_DIR)',
                            'files': [
                                '<(NIM_SDK_DIR)/bin/nim_chatroom.dll',
                                '<(NIM_SDK_DIR)/bin/nim_chatroom_cpp_wrapper.dll'
                            ]
                        }],
                        'defines': [
                            'NIM_WIN_DESKTOP_ONLY_SDK',
                            'NIM_SDK_DLL_IMPORT',
                            'CPPWRAPPER_DLL',
                            'WIN32',
                            'WIN32_LEAN_AND_MEAN'
                        ],
                        'library_dirs': [
                            '<(NIM_SDK_DIR)/lib/',
                        ],
                        'link_settings': {
                            'libraries': [
                                '-lnim_chatroom_cpp_wrapper.lib',
                                '-lnim_wrapper_util.lib'
                            ]
                        },
                        'msvs_settings': {
                            'VCCLCompilerTool': {
                                'AdditionalOptions': [
                                    '/utf-8'
                                ]
                            }
                        },
                        'defines!': [
                        ],
                        'sources': [
                        ],
                        'include_dirs': [
                            '<(NIM_SDK_DIR)/include/',
                            '<(SOURCE_DIR)/src/'
                        ],
                        'configurations': {
                            'Release': {
                                'msvs_settings': {
                                    'VCCLCompilerTool': {
                                        'RuntimeLibrary': '2',
                                        'Optimization': '2',
                                        'EnableIntrinsicFunctions': 'true',
                                        'DebugInformationFormat': '3',
                                        'AdditionalOptions': [
                                        ]
                                    }
                                },
                            },
                            'Debug': {
                                'msvs_settings': {
                                    'VCCLCompilerTool': {
                                        'RuntimeLibrary': '3',
                                        'AdditionalOptions': [
                                        ]
                                    }
                                },
                            }
                        }
                    }
                ],
                [
                    'OS=="mac"',
                    {
                        'copies': [{
                            'destination': '<(PRODUCT_DIR)',
                            'files': [
                                '<(NIM_SDK_DIR)/framework/nim_chatroom.framework'
                            ]
                        }],
                        'defines': [
                            'NIM_SDK_DLL_IMPORT',
                            'OS_MACOSX'
                        ],
                        'mac_framework_dirs': [
                            '../nim_sdk/framework'
                        ],
                        'library_dirs': [
                            '../nim_sdk/lib',
                            '../nim_sdk/framework'
                        ],
                        'link_settings': {
                            'libraries': [
                                'libnim_wrapper_util.a',
                                'libnim_chatroom_cpp_wrapper.a',
                                'nim_chatroom.framework',
                                '-Wl,-rpath,@loader_path'
                            ]
                        },
                        'defines!': [
                            '-std=c++11'
                        ],
                        'sources': [
                        ],
                        'include_dirs': [
                            '<(SOURCE_DIR)/src/',
                            '<(NIM_SDK_DIR)/include/',
                            '<(NIM_SDK_DIR)/framework/nim.framework/Headers/',
                        ],
                        'xcode_settings': {
                            'ARCHS': ['x86_64'],
                            'MACOSX_DEPLOYMENT_TARGET': '10.14',
                            'EXCUTABLE_EXTENSION': 'node',
                            'FRAMEWORK_SEARCH_PATHS': [],
                            'DEBUG_INFORMATION_FORMAT': 'dwarf-with-dsym',
                            'OTHER_CFLAGS': [
                            ],
                        }
                    }
                ]
            ]
        }
    ]
}

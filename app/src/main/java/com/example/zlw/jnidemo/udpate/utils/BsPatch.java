package com.example.zlw.jnidemo.udpate.utils;

public class BsPatch {

	/**
	 * 合并
	 * 
	 * @param oldfile
	 * @param newfile
	 * @param patchfile
	 */
	public native static void patch(String oldfile, String newfile, String patchfile);

	static{
		System.loadLibrary("libpatch");
	}
	
}

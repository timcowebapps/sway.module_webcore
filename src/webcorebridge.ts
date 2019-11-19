"use strict";

import * as _ from "underscore";
import { IWebcoreBridgeModule } from "./webcorebridgemodule";

export class WebcoreBridge {
	public module: IWebcoreBridgeModule = null;

	private static instance: WebcoreBridge;
	static getInstance(moduleObj: any): WebcoreBridge {
		WebcoreBridge.instance = WebcoreBridge.instance || new WebcoreBridge(moduleObj);
		return WebcoreBridge.instance;
	}

	private _isInitialized: boolean = false;

	constructor(moduleObj: any) {
		if (WebcoreBridge.instance)
			throw new Error("Error - use Singleton.getInstance()");

		this.module = moduleObj;
	}

	public initialize(timeout: number = 3000): Promise<boolean> {
		if (this._isInitialized)
			return Promise.resolve(true);

		return new Promise((resolve, reject) => {
			const timeoutId = setTimeout(() => resolve(false), timeout);

			this.module.onAbort = (reason: Error | any) => {
				if (this._isInitialized) {
					// Empty
				} else {
					clearTimeout(timeoutId);
					console.log(`initializeRuntime: failed to initialize module`, reason);
					throw reason instanceof Error ? reason : new Error(reason);
				}
			}

			this.module.onRuntimeInitialized = () => {
				clearTimeout(timeoutId);
				this._isInitialized = true;
				console.log(`initializeRuntime: successfully initialized module`);
				resolve(true);
			}
		});
	}
};

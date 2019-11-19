"use strict";

import * as _ from "underscore";
import * as Module from "../../sway.module_webapp-mvc/bin/sway.module_webcore.js";
import { IWebcoreBridgeModule } from "./webcorebridgemodule";

export class WebcoreBridge {
	private static instance: WebcoreBridge;
	static getInstance(): WebcoreBridge {
		WebcoreBridge.instance = WebcoreBridge.instance || new WebcoreBridge();
		return WebcoreBridge.instance;
	}

	private _isInitialized: boolean = false;

	constructor(public module: IWebcoreBridgeModule = null) {
		if (WebcoreBridge.instance)
			throw new Error("Error - use Singleton.getInstance()");

		this.module = Module();
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

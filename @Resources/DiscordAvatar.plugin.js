/**
 * @name DiscordAvatar
 * @author ordinall
 * @authorId 374663636347650049
 * @version 1.0.0
 */

module.exports = (_ => {
	const config = {
		"info": {
			"name": "DiscordAvatar",
			"authors": [{
				"name": "ordinall",
				"discord_id": "374663636347650049",
				"github_username": "ordinall",
			}],
			"version": "1.0.0",
			"description": "Extracts user's avatar profile picture url",
		},
		// defaultConfig: [
		// 	{
		// 		type: "file",
		// 		name: "Text file path",
		// 		id: "path",
		// 		value: {}
		// 	},
		// ],
		"main": "index.js"
	};
	return !global.ZeresPluginLibrary ? class {
		constructor() {this._config = config;}
		getName() {return config.info.name;}
		getAuthor() {return config.info.authors.map(a => a.name).join(", ");}
		getDescription() {return config.info.description;}
		getVersion() {return config.info.version;}
		load() {
			BdApi.showConfirmationModal(
				"Library plugin is needed",
				[`The library plugin needed for ${config.info.name} is missing. Please click Download to install it.`], 
				{
					confirmText: "Download",
					cancelText: "Cancel",
					onConfirm: () => {
						require("request").get("https://rauenzi.github.io/BDPluginLibrary/release/0PluginLibrary.plugin.js", async (error, response, body) => {
							if (error) {
								return BdApi.showConfirmationModal("Error Downloading",
									[
										"Library plugin download failed. Manually install plugin library from the link below.",
										BdApi.React.createElement("a", { href: "https://rauenzi.github.io/BDPluginLibrary/release/0PluginLibrary.plugin.js", target: "_blank" }, "Plugin Link")
									],
								);
							}
							await new Promise(r => require("fs").writeFile(require("path").join(BdApi.Plugins.folder, "0PluginLibrary.plugin.js"), body, r));
						});
					}
				}
			);
		}
		start() {}
		stop() {}
	} : (([Plugin, Api]) => {
		const plugin = (Plugin, Library) => {
			const { Patcher, WebpackModules, Toasts, Settings } = Library;
			return class DiscordAvatar extends Plugin {
				constructor() {
					super();
				}

				start() {
					this.interv = setInterval(this.doStuff, 30000);
					this.doStuff();
				}

				doStuff() {
					//if (this.settings.path instanceof File) {
						let elem = document.getElementsByClassName("avatar-SmRMf2 wrapper-3t9DeA");
						let src = elem[0].firstElementChild.firstElementChild.firstElementChild.firstElementChild.src;
						//console.log(this.settings.path);
						require("fs").writeFile(require('os').homedir() + "\\Documents\\Rainmeter\\Skins\\Amarena\\@Resources\\Images\\DiscordAv.txt", src.replace(/(?:\?size=\d{2,4})?$/, "?size=4096"), err => {});
					//} else {
					// 	setTimeout(() => {
					// 		Toasts.show("Please set the file path in DiscordAvatar's settings", { type: "info", timeout: 6000 }),
					// 		console.log(this.settings.path)
					// 	}, 3000);
					// }
				}

				// getSettingsPanel() {
				// 	const panel = this.buildSettingsPanel();
				// 	panel.addListener(() => {
				// 		this.doStuff();
				// 		this.saveSettings();
				// 	});
				// 	return panel.getElement();
				// }

				stop() {
					clearInterval(this.interv);
				}
			};
		};
		return plugin(Plugin, Api);
	})(global.ZeresPluginLibrary.buildPlugin(config));
})();